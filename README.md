# FolderSize

This a small C++ project derived from a bigger ongoing project of mine. 

FolderSize is a lightweight tool for folder size measurement aimed at reaching tremendous speeds.

## Usage
``FolderSize [Path]``

## Notice

- Folder which the program does not have permission to access will be skipped.

- Windows is significantly slower when compared against Linux on the same hardware, expect up to **500%** higher speed coming from Windows to Linux

- **As far as I am aware, this solution reaches the lowest possible evaluation time, even switching to a lighter language like C no longer yields better results.**

## Building

### Visual Studio

You can build this project yourself in Visual Studio, with the following project property settings:
- General > **Windows SDK Version**: `10.0.22000.0`
- General > **Platform Toolset**: `Visual Studio 2017 (v141)`
- C/C++ > Language > **C++ Language Standard**: `ISO C++ Latest Draft Standard (/std:c++latest)`

### Others

In every case `c++17` standard is **necessary**

G++ Example: `g++ -std=c++17 FolderSize.cpp -o FolderSize`
