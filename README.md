
```sh
# Build and run

# Linux
cmake --preset linux-x64-debug -B./out/linux-x64-debug/build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=./cmake/toolchain-linux-x64.cmake  && cmake --build ./out/linux-x64-debug/build --config Debug && cp ./src/mortest.conf ./out/linux-x64-debug/build/mortest.conf & ./out/linux-x64-debug/build/mortest

# Windows
cmake --preset windows-x64-debug -B./out/windows-x64-debug/build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=./cmake/toolchain-windows-x64.cmake & cmake --build ./out/windows-x64-debug/build --config Debug & xcopy src\mortest.conf out\windows-x64-debug\build /Y & out\windows-x64-debug\build\mortest.exe & ECHO %ERRORLEVEL%
```