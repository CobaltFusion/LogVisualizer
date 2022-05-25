cmake -G "Ninja" -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./deploy .
cd build
ninja install