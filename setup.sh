
if [ ! -d build ];then
    mkdir build
else
    echo build exist
fi
cmake -S ./ -B ./build/
cd build
make
cp ninetails ../
cd ..
rm -r build