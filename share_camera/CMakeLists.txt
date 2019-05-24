## Build visualizer_vtk
find_package(Qt5 COMPONENTS Widgets)
if (NOT TARGET Qt5::Widgets)
  message("Skipping example: ${Qt5_NOT_FOUND_MESSAGE}")
  return ()
endif ()

# Set your files and resources here
set(Srcs
  ShareCameraQt.cxx
  ShareCameraQtDriver.cxx)

set(Hdrs
  ShareCameraQt.h)

set(UIs
  ShareCameraQt.ui)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

source_group("Resources" FILES
  ${UIs})

# CMAKE_AUTOMOC in ON so the MocHdrs will be automatically wrapped.
add_executable(share_camera MACOSX_BUNDLE
  ${Srcs} ${Hdrs} ${UIs})

target_link_libraries(share_camera
  PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    VTK::CommonCore
    VTK::CommonColor
    VTK::FiltersSources
    VTK::InteractionStyle
    VTK::InteractionWidgets
    VTK::RenderingContextOpenGL2
    VTK::RenderingCore
    VTK::RenderingFreeType
    VTK::RenderingGL2PSOpenGL2
    VTK::RenderingOpenGL2
    VTK::RenderingQt
    VTK::ChartsCore
    VTK::InfovisCore
    VTK::ViewsContext2D
    VTK::ViewsQt
    VTK::GUISupportQt)

target_include_directories(share_camera PUBLIC
      "${CMAKE_CURRENT_SOURCE_DIR}"
      "${CMAKE_CURRENT_BINARY_DIR}"
      "$<TARGET_PROPERTY:VTK::CommonCore,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::FiltersSources,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::InteractionStyle,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::InteractionWidgets,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::RenderingFreeType,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::RenderingQt,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::ChartsCore,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::ViewsContext2D,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::RenderingContextOpenGL2,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::RenderingOpenGL2,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::RenderingCore,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::InfovisCore,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::ViewsQt,INTERFACE_INCLUDE_DIRECTORIES>"
      "$<TARGET_PROPERTY:VTK::GUISupportQt,INTERFACE_INCLUDE_DIRECTORIES>")

