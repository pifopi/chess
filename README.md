# chess

external libs/tools used :

| library / tool | link                         |
|----------------|------------------------------|
| Qt 5.10.0      | <https://www.qt.io/download> |

To generate the project, you must define :

| define            | description                            | windows example          | linux example                |
|-------------------|----------------------------------------|--------------------------|------------------------------|
| CMAKE_PREFIX_PATH | path of your installation of Qt 5.10.0 | C:/Qt/5.10.0/msvc2017_64 | /home/gael/Qt/5.10.0/gcc_64/ |

# Visual studio

Don't forget to modify your working directory to $(SolutionDir)

# GCC

Don't forget to launch the executable from it's own directory (to find the copied resources)

Here is an example of the command line I do to set up the project

```
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
```