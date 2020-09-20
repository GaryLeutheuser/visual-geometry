# visual-geometry
A simple graphical library based on Qt for visualization of points and line segments.

# Installation
To build and install the library, perform the following in the root directory of the project (where `CMakeLists.txt` is located). Use whatever build tool you like instead of ninja.
```
$ cmake . -B build . -G Ninja
$ cd build
# cmake --build . --target install
```

Note that the last command requires root to actually install the library into the proper directories.

The shared object file is installed to `/usr/local/lib`, the header file is installed to `/usr/local/include`, and the package configuration file is installed to `/usr/local/share/pkgconfig`.

Here's an example contents of a CMakeLists.txt file for consuming the library. If `PKG_CONFIG_PATH` already includes `/usr/local/share/pkgconfig`, that part of the file may not be needed.
```
cmake_minimum_required(VERSION 3.18)

project(example)

find_package(PkgConfig REQUIRED)

set(ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:/usr/local/share/pkgconfig")
pkg_check_modules(VisualGeometry REQUIRED IMPORTED_TARGET
    visual-geometry)

add_executable(example example.cpp)

target_link_libraries(example PUBLIC
    PkgConfig::VisualGeometry)
```

Ultimately, you just need to `#include <visual-geometry.h>` and link with `visual-geometry`.
