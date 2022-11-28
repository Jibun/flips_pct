# FLIPedaç - L'aplicador de pedaços de 'Ce Trencada' ![Logotip de FLIPedaç](./flips.ico)

FLIPedaç és la traducció al català de [Floating IPS (or Flips)](https://github.com/Alcaro/Flips), un aplicador de pedaços (patch) de tipus IPS i BPS amb una interfície simple, però molt capaç.

![IPS](./ips.ico) ![BPS](./bps.ico)

La traducció ha estat feta per Nil CM (TW: [@PelochoRockea](https://twitter.com/PelochoRockea)) per a ['Ce Trencada'](https://cetrencada.cat/).
Trobeu-hi més informació al següent [enllaç](https://www.cetrencada.cat/comunitat/?eina=flipedaç).

### Característiques
- Crea els pedaços BPS més petits que cap altra eina, i més ràpidament que d'altres comparables.
- Crea els pedaços IPS més petits que cap altra eina, també (però només una mica més menuts, ja que Lunar IPS és molt bo).
- Interfície completa per a Windows amb GTK+, incloent-hi suport per a la consola de comandes: pot ser emprat únicament des de la consola de forma completa (*nota: és possible que alguns caràcters no es visualitzin de forma correcta per motius de compatibilitat*).
- Pot aplicar múltiples pedaços a la mateixa ROM, creant una bona pila de ROMs (no disponible en consola de comandes).
- Recorda quines ROMs heu fet servir, i l'empra de nou si creu que és correcte (no disponible en consola de comandes, només per a BPS).
- Pot obrir altres programes després d'aplicar el pedaç a la ROM; i juntament amb l'anterior, permet obrir un emulador fent doble clic a un fitxer BPS (no disponible en consola de comandes).

### Altres eines basades en FLIPS
Aquí sota es llisten altres eines d'aplicació de pedaços basats en FLIPS (algunes per a altres plataformes):
- [Floating IPS](https://github.com/Alcaro/Flips): el Floating IPS original.
- [MultiPatch](https://projects.sappharad.com/tools/multipatch.html): per a MacOS, aplica BPS/IPS/UPS/PPF/Xdelta/bsdiff/Ninja2 i crea BPS/IPS/XDelta/bsdiff.
- [QtFloatingIPS](https://github.com/covarianttensor/QtFloatingIPS): Port de FLIPS a MacOS.
- [Wh0ba Floating IPS](https://wh0ba.github.io/repo/): Port de FLIPS a iOS/Cydia.
- [RomPatcher.js](https://www.marcrobledo.com/RomPatcher.js/): JavaScript, aplica APS/BPS/IPS/PPF/RUP/UPS/Xdelta i crea APS/BPS/IPS/RUP/UPS.

## Compilació

### Linux (Debian/Ubuntu):
- `sudo apt-get install g++ build-essential` per instal·lar el compilador.
- `sudo apt-get install libgtk-3-dev pkg-config` per instal·lar la llibreria gràfica de l'aplicació.
- `./make.sh` per a fer una versió només consola, per a la versió completa empreu `make CFLAGS=-g`.

### Altres Linux:
- Instal·leu `make` i `g++`.
- Per a la llibreria gràfica instal·leu `pkg-config` i `GTK+ 3 headers`.
- Per a suport de perfilació, instal·leu també `curl` o `wget`.
- `./make.sh` per a fer una versió només consola, per a la versió completa empreu `make CFLAGS=-g`.

### MacOS, altres Unix o qualsevol màquina amb un compilador de C++:
- Instal·leu un compilador de C++ compatible amb el vostre dispositiu.
- Empreu `clang++ *.c *.cpp -O3 -o flips`.
- Per a la llibreria gràfica GTK, empreu alguna variant apropiada de `clang++ *.c *.cpp -O3 -o flips -DFLIPS_GTK -lgtk3`.
- Per a una millor optimització (perfilació/etc), extraieu les comandes apropiades dels fitxers `Makefile` i `make.sh`.

### Windows:
- Instal·leu [mingw-w64](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-win32/seh/), o similar.
- Empreu `make CFLAGS=-O3` (interfície gràfica habilitada per defecte), o extraieu les comandes d'optimització apropiades del fitxer `make.sh`.

## Instruccions d'ús
- Per a ús amb interfície gràfica executeu el programa. El títol de les finestres de selecció de fitxers estipulen què necessiten en aquell moment.
- Per a ús amb consola de comandes, empreu `./flips --help` (*nota: és possible que alguns caràcters no es visualitzin de forma correcta per motius de compatibilitat*).

## Crèdits
Floating IPS (FLIPS) i codi original: [Alcaro](https://github.com/alcaro/).

FLIPedaç, traducció i localització: [NilCM](https://github.com/Nilcm01/).
