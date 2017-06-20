======================= HOW TO BUILD A CMAKE EXECUTABLE ========================

/ = racine du repo

========= WINDOWS ===========

Executable: /install/indieStudio.exe

mkdir build
cd build
cmake -G "Visual Studio 15 2017 Win64" ..
cmake --build .
cmake --build --target install
cd ../install
./indieStudio.exe

======== LINUX ============

Executable: /build/indieStudio (Emplacement temporaire)

mkdir build
cd build
cmake ..
make
./indieStudio