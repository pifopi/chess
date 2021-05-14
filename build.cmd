pushd %~dp0

mkdir bin
cd bin
cmake ../src -G "Visual Studio 16 2019" -DCMAKE_PREFIX_PATH=C:/Qt/Qt5.12.10/5.12.10/msvc2017_64
MSBuild.exe .\chess.vcxproj /p:Configuration=Debug
MSBuild.exe .\chess.vcxproj /p:Configuration=Release
MSBuild.exe .\chess.vcxproj /p:Configuration=RelWithDebInfo
MSBuild.exe .\chess.vcxproj /p:Configuration=MinSizeRel

popd
