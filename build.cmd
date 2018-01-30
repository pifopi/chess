pushd %~dp0

mkdir bin
cd bin
cmake ../src -G "Visual Studio 15 2017 Win64" -DCMAKE_PREFIX_PATH=C:/Qt/5.10.0/msvc2017_64
MSBuild.exe .\main.vcxproj /p:Configuration=Debug
MSBuild.exe .\main.vcxproj /p:Configuration=Release
MSBuild.exe .\main.vcxproj /p:Configuration=RelWithDebInfo
MSBuild.exe .\main.vcxproj /p:Configuration=MinSizeRel

popd
