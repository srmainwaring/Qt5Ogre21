cmake_minimum_required(VERSION 3.10.2)

#------------------------------------------------------------------------
# Configure Qt

qt5_add_resources(QT_RESOURCES
#     Main.qrc
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#------------------------------------------------------------------------
# Build

add_executable(Qt5Ogre21
    qogreviewport.h
    qogreviewport.cpp
    qtogre21.h
    qtogre21.cpp
    somecustomwidget.h
    somecustomwidget.cpp
    test.cpp
    ${QT_RESOURCES}
)

target_include_directories(Qt5Ogre21 PUBLIC
    ${OGRE2_INCLUDE_DIRS}
)

target_link_libraries(Qt5Ogre21 PUBLIC
    ${OGRE2_LIBRARIES}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    # Qt5::Qml
    # Qt5::Quick
)

set_target_properties(Qt5Ogre21
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

#------------------------------------------------------------------------
# Install

