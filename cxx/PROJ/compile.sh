# --- pre
rm -rf build
mkdir build
rm -rf bin
mkdir bin
cd build

# --- rmake
cmake \
    -G "MinGW Makefiles" \
    ..
make

# --- clean
cd ../bin
# rm *.a


# --- run
echo ""
./project.exe