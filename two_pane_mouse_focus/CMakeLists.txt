## Build visualizer_vtk
find_package(Qt5 COMPONENTS Widgets)
if (NOT TARGET Qt5::Widgets)
  message("Skipping example: ${Qt5_NOT_FOUND_MESSAGE}")
  return ()
endif ()

# Set your files and resources here
set( Srcs main.cxx GUI4.cxx )

set( Hdrs GUI4.h )

set( MOC_Hdrs GUI4.h )

set( UIs GUI4.ui )

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# CMAKE_AUTOMOC in ON so the MocHdrs will be automatically wrapped.
add_executable(qtevents
  MACOSX_BUNDLE  ${Srcs} ${Hdrs} ${UI_Srcs} ${MOC_Hdrs})

target_link_libraries(qtevents
  PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    VTK::CommonCore
    VTK::FiltersSources
    VTK::GUISupportQt)

target_include_directories(qtevents PUBLIC
      "${CMAKE_CURRENT_SOURCE_DIR}"
      "${CMAKE_CURRENT_BINARY_DIR}"
      "$<TARGET_PROPERTY:VTK::CommonCore,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::FiltersSources,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::GUISupportQt,INTERFACE_INCLUDE_DIRECTORIES>")

