cmake_minimum_required(VERSION 2.8.11)

project(QtVtkViewer)

set(CMAKE_CONFIGURATION_TYPES "Release")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# List source files & resources
set(Sources main.cpp  mainwindow.cpp  scenewidget.cpp)
file (GLOB_RECURSE Headers *.h)
file (GLOB_RECURSE Resources *.qrc)
file (GLOB_RECURSE UIs *.ui)

# Find package Qt
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)

# Use Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
qt5_add_resources(Resources ${Resources})

# Find package VTK
find_package(VTK REQUIRED)

# Use VTK
include_directories(${VTK_INCLUDE_DIRS})

# Build executable
add_executable(QtVtkViewer MACOSX_BUNDLE ${Sources} ${Headers} ${Resources} ${UIs})

# Link libraries
target_link_libraries(QtVtkViewer Qt5::Widgets Qt5::OpenGL ${VTK_LIBRARIES})
