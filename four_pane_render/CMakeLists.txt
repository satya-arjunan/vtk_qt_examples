## Build visualizer_vtk
find_package(Qt5 COMPONENTS Widgets)
if (NOT TARGET Qt5::Widgets)
  message("Skipping example: ${Qt5_NOT_FOUND_MESSAGE}")
  return ()
endif ()

# Set your files and resources here
set(Srcs
  QtVTKRenderWindowsApp.cxx
  QtVTKRenderWindows.cxx)

set(Hdrs
  QtVTKRenderWindows.h)

set(UIs
  QtVTKRenderWindows.ui)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# CMAKE_AUTOMOC in ON so the MocHdrs will be automatically wrapped.
add_executable(QtVTKRenderWindows
  ${Srcs} ${Hdrs} ${UIs})

target_link_libraries(QtVTKRenderWindows
  PRIVATE
    Qt5::Widgets
    VTK::CommonCore
    VTK::GUISupportQt
    VTK::IOImage
    VTK::ImagingColor
    VTK::ImagingGeneral
    VTK::InteractionImage
    VTK::InteractionStyle
    VTK::InteractionWidgets)

target_include_directories(QtVTKRenderWindows PUBLIC
      "${CMAKE_CURRENT_SOURCE_DIR}"
      "${CMAKE_CURRENT_BINARY_DIR}"
      "$<TARGET_PROPERTY:VTK::CommonCore,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::RenderingCore,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::GUISupportQt,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::InteractionImage,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::InteractionWidgets,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::FiltersGeneral,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::FiltersSources,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::FiltersProgrammable,INTERFACE_INCLUDE_DIRECTORIES>")

