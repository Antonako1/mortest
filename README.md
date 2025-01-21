
```sh
# Build and run

# Linux
cmake --preset linux-x64-debug -B./out/linux-x64-debug/build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=./cmake/toolchain-linux-x64.cmake  && cmake --build ./out/linux-x64-debug/build --config Debug && cp ./src/mortest.conf ./out/linux-x64-debug/build/mortest.conf & ./out/linux-x64-debug/build/mortest

# Windows
cmake --preset windows-x64-debug -B./out/windows-x64-debug/build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=./cmake/toolchain-windows-x64.cmake & cmake --build ./out/windows-x64-debug/build --config Debug & xcopy src\mortest.conf out\windows-x64-debug\build /Y & out\windows-x64-debug\build\mortest.exe & ECHO %ERRORLEVEL%

# VS
cmake --preset VS2022-x64-debug & .\out\build\VS2022-x64-debug\mortest.sln
cmake -S . -B out\win_32 -DCMAKE_BUILD_TYPE=Debug -G "Visual Studio 17 2022" -A Win32 & cmake --build out\win_32
cmake -S . -B out\win_64 -DCMAKE_BUILD_TYPE=Debug -G "Visual Studio 17 2022" -A x64 & cmake --build out\win_64 & .\out\win_64\Debug\mortest.exe
```