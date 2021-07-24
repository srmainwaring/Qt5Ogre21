cmake_minimum_required(VERSION 3.10.2)
project(ogre_tutorials)

#------------------------------------------------------------------------
# Compile as C++14

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#------------------------------------------------------------------------
# Find ignition-cmake
find_package(ignition-cmake2 2.3 REQUIRED)
set(IGN_CMAKE_VER ${ignition-cmake2_VERSION_MAJOR})

#------------------------------------------------------------------------
# Find OGRE2
ign_find_package(IgnOGRE2 VERSION 2.1.2
    COMPONENTS HlmsPbs HlmsUnlit Overlay
    REQUIRED_BY ogre2
    PRIVATE_FOR ogre2)

if (OGRE2_FOUND)
  set(HAVE_OGRE2 TRUE)
endif()

#------------------------------------------------------------------------
# Find Qt
find_package(Qt5 REQUIRED COMPONENTS
    Core
    Gui
    Qml
    Quick
    QuickControls2
    Widgets
)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Qml_INCLUDE_DIRS}
    ${Qt5Quick_INCLUDE_DIRS}
    ${Qt5QuickControls2_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
)

add_definitions(
    ${Qt5Widgets_DEFINITIONS}
    ${Qt5Qml_DEFINITIONS}
    ${${Qt5Quick_DEFINITIONS}}
)

#------------------------------------------------------------------------
# Subdirectories

add_subdirectory(Qt5Ogre21)

#------------------------------------------------------------------------
# Install resources

# file(COPY ${PROJECT_SOURCE_DIR}/cfg DESTINATION ${CMAKE_BINARY_DIR}/bin)
# file(COPY ${PROJECT_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR}/bin)