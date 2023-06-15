#include <shlobj.h>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <io.h> // For _finddata_t, _wfindfirst, _wfindnext, _findclose
#include <sys/stat.h> // For _S_IFDIR

#include <Windows.h>
#include <Shlwapi.h>

using namespace std; 

#include "tools.h"

vector<wstring> FindPatchFiles(const wchar_t* folder_path) {
    vector<wstring> patch_files;

    // Open the directory using _wfindfirst and _wfindnext
    _wfinddata_t file_info;
    intptr_t handle = _wfindfirst((wstring(folder_path) + L"\\*.*").c_str(), &file_info);

    if (handle != -1) {
        do {
            // Check if the file is a regular file
            if (!(file_info.attrib & _A_SUBDIR)) {
                // Get the file extension
                wstring extension = wstring(file_info.name).substr(wstring(file_info.name).find_last_of(L'.') + 1);

                // Check if the extension matches "*.ips", "*.bps", or "*.ups"
                if (extension == L"ips" || extension == L"bps" || extension == L"ups") {
                    // Add the file to the list of patch files
                    patch_files.push_back(wstring(folder_path) + L"\\" + file_info.name);
                }
            }
        } while (_wfindnext(handle, &file_info) == 0);

        // Close the directory handle
        _findclose(handle);
    }

    // Sort the patch files alphabetically
    sort(patch_files.begin(), patch_files.end());

    return patch_files;
}

/*static int CALLBACK BrowseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{

    if(uMsg == BFFM_INITIALIZED)
    {
        SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);
    }

    return 0;
}*/

bool BrowseFolder(WCHAR* path, WCHAR* message)
{
    /*WCHAR current[MAX_PATH];
    wcscpy(current, L"");*/

    BROWSEINFOW bi = { 0 };
    bi.lpszTitle = message;
    bi.ulFlags    = BIF_RETURNONLYFSDIRS || BIF_USENEWUI || BIF_BROWSEINCLUDEURLS;
    /*bi.lpfn       = BrowseCallbackProc;
    bi.lParam     = (LPARAM) current;*/

    LPITEMIDLIST pidl = SHBrowseForFolderW ( &bi );

    if (pidl != 0)
    {
        // get the name of the folder and put it in path
        SHGetPathFromIDListW ( pidl, path );

        // free memory used
        IMalloc * imalloc = 0;
        if (SUCCEEDED( SHGetMalloc ( &imalloc )))
        {
            imalloc->Free ( pidl );
            imalloc->Release ( );
        }

        return true;
    }

    return false;
}

bool FindMatchingFile(const WCHAR* patchname, const WCHAR* destinationPath, WCHAR* matchingFile, bool removeExtension)
{
    WCHAR patchfilename[MAX_PATH];
    wcscpy(patchfilename, patchname);

    // Remove the path to the patch file, if any
    WCHAR* patchnameonly = wcsrchr(patchfilename, L'\\');
    if (patchnameonly != NULL)
    {
        patchnameonly++;
    }
    else
    {
        patchnameonly = patchfilename;
    }

    // Remove the extension from the patch filename
    if (removeExtension) {
        WCHAR* patchext = wcsrchr(patchnameonly, L'.');
        if (patchext != NULL)
        {
            *patchext = L'\0';
        }
    } else {
        WCHAR* patchext = wcsrchr(patchnameonly, L'.');
        if (patchext != NULL)
        {
            patchext = wcslwr(patchext);
        }
    }

    // Open the directory using _wfindfirst and _wfindnext
    _wfinddata_t file_info;
    intptr_t handle = _wfindfirst((wstring(destinationPath) + L"\\*.*").c_str(), &file_info);

    if (handle != -1) {
        do {
            // Check if the file is a regular file
            if (!(file_info.attrib & _A_SUBDIR)) {

                WCHAR* filename = new WCHAR[MAX_PATH];
                wcscpy(filename, file_info.name);

                // Remove the extension from the file name
                if (!removeExtension) {
                    WCHAR* fileext = wcsrchr(filename, L'.');
                    if (fileext != NULL)
                    {
                        fileext = wcslwr(fileext);
                    }
                }

                if (lstrcmpiW(filename, patchnameonly) == 0)
                {
                    
                    swprintf(matchingFile, MAX_PATH, L"%S\\%S", destinationPath, filename);

                    // Close the directory handle
                    _findclose(handle);

                    return true;
                }
            }
        } while (_wfindnext(handle, &file_info) == 0);

        // Close the directory handle
        _findclose(handle);
    }
    return false;
}

string WStringToString(const wstring& wstr)
{
	string str;
	size_t size;
	str.resize(wstr.length());
	wcstombs_s(&size, &str[0], str.size() + 1, wstr.c_str(), wstr.size());
	return str;
}