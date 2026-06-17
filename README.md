# raytracing1

This is a project following a tutorial called "ray tracing in one weekend". Just trying to stay active in coding and expand my knowledge in computer graphics!

## Building the projects

- Install cmake by searching "cmake download" on the web and going to the official website
- ensure it is added to windows PATH so that you can run cmake commands in terminal (I ran export PATH=$PATH:"/c/Program Files/CMake/bin")
- create a CMakeLists.txt file. this is necessary to be able to run cmake commands
- add this into the txt file: 

cmake_minimum_required(VERSION 3.10)

project(inOneWeekend)

set(CMAKE_CXX_STANDARD 17)

add_executable(inOneWeekend main.cpp)

- then run

cmake -B build
cmake --build build

- and then this next line will run the code and generate an image file 

./build/Debug/InOneWeekend.exe > image.ppm

- and finally you'll just have to open up the image in an image viewer, whether thats just through a website that can do it or a vscode extension you found or some other way. I'm using the vscode extension "PBM/PPM/PGM Viewer for Visual Studio Code" by ngtystr, which makes it so that instead of displaying the pixel value numbers when you open a ppm file, it actually displays the image.


### for later speed-optimized builds

- run 

cmake --build build --config release

- then run the program like this

build\Release\inOneWeekend.exe > image.ppm


