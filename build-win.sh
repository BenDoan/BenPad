qmake-qt4 -spec win32-g++-cross -r BenPad.pro
make
cp windows_libs/* release
