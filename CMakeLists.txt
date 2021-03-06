cmake_minimum_required(VERSION 3.18)
project(visual-geometry VERSION 1.0.0 DESCRIPTION "Simple geometry visualization tool based on Qt")

include_directories("src/include")

add_library(visual-geometry SHARED
    src/display.cpp
    src/point.cpp
    src/line.cpp
    src/plot.cpp)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
target_link_libraries(visual-geometry Qt5::Widgets)

set_target_properties(visual-geometry PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(visual-geometry PROPERTIES PUBLIC_HEADER include/visual_geometry.h)
target_include_directories(visual-geometry PRIVATE .)
target_include_directories(visual-geometry PRIVATE include)

configure_file(visual-geometry.pc.in visual-geometry.pc @ONLY)

include(GNUInstallDirs)

install(TARGETS visual-geometry
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_BINARY_DIR}/visual-geometry.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
