# chess

external libs/tools used :

| library / tool | link                         |
|----------------|------------------------------|
| Qt 5.12.10     | <https://www.qt.io/download> |

To generate the project, you must define :

| define            | description                             | windows example                     | linux example                 |
|-------------------|-----------------------------------------|-------------------------------------|-------------------------------|
| CMAKE_PREFIX_PATH | path of your installation of Qt 5.12.10 | C:/Qt/Qt5.12.10/5.12.10/msvc2017_64 | /home/gael/Qt/5.12.10/gcc_64/ |

# Visual studio

Don't forget to modify your working directory to $(SolutionDir)

You have an example on how to build with build.cmd

# GCC

Don't forget to launch the executable from its own directory (to find the copied resources)

You have an example on how to build with build.sh