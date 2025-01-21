Uses ATRC version [2.2.0](https://github.com/Antonako1/ATRC/releases/tag/v2.2.0)

```shell
# VS
# 32-bit
cmake -S . -B out\win_32 -DCMAKE_BUILD_TYPE=Debug -G "Visual Studio 17 2022" -A Win32 & cmake --build out\win_32 & .\out\win_32\Debug\mortest.exe
# 64-bit
cmake -S . -B out\win_64 -DCMAKE_BUILD_TYPE=Debug -G "Visual Studio 17 2022" -A x64 & cmake --build out\win_64 & .\out\win_64\Debug\mortest.exe
```