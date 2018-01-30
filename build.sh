mkdir bin
cd bin
mkdir Debug
mkdir Release
mkdir RelWithDebInfo
mkdir MinSizeRel
cd Debug
cmake ../../src -DCMAKE_PREFIX_PATH=/home/gael/Qt/5.10.0/gcc_64/ -DCMAKE_BUILD_TYPE=Debug
make
cd ../Release
cmake ../../src -DCMAKE_PREFIX_PATH=/home/gael/Qt/5.10.0/gcc_64/ -DCMAKE_BUILD_TYPE=Release
make
cd ../RelWithDebInfo
cmake ../../src -DCMAKE_PREFIX_PATH=/home/gael/Qt/5.10.0/gcc_64/ -DCMAKE_BUILD_TYPE=RelWithDebInfo
make
cd ../MinSizeRel
cmake ../../src -DCMAKE_PREFIX_PATH=/home/gael/Qt/5.10.0/gcc_64/ -DCMAKE_BUILD_TYPE=MinSizeRel
make
