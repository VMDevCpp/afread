@ECHO OFF

ECHO 1.Debug
ECHO 2.Release
ECHO 3.Exit
ECHO.

CHOICE /C 123 /M "Enter your choice:"

@ECHO ON

GOTO choice-%errorlevel%

:choice-1
mkdir ..\_build\DebugEclipseNinjaClang
cd ..\_build\DebugEclipseNinjaClang
cmake -G "Eclipse CDT4 - Ninja" -DCMAKE_ECLIPSE_GENERATE_LINKED_RESOURCES=FALSE -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -D CMAKE_BUILD_TYPE=Debug ../../source
GOTO End

:choice-2
mkdir ..\_build\ReleaseEclipseNinjaClang
cd ..\_build\ReleaseEclipseNinjaClang
cmake -G "Eclipse CDT4 - Ninja" -DCMAKE_ECLIPSE_GENERATE_LINKED_RESOURCES=FALSE -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -D CMAKE_BUILD_TYPE=Release ../../source
GOTO End

:choice-3
:End