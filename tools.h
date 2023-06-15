#include <bits/stdc++.h>
#include <vector>

bool BrowseFolder(WCHAR* path, WCHAR* message);
std::vector<std::wstring> FindPatchFiles(LPCWSTR folder_path);
void SearchFolder( WCHAR * path , std::vector<std::string> patchnames);
bool FindMatchingFile(const WCHAR* patchname, const WCHAR* destinationPath, WCHAR* matchingFile, bool removeExtension = true);
std::string WStringToString(const std::wstring& wstr);