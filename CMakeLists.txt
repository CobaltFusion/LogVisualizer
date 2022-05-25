# cmake_minimum_required(VERSION 3.16)

# project(LogVisualizer)

# include(CheckCXXCompilerFlag)
# include(CheckCXXSourceCompiles)
# include(CheckIncludeFile)
# include(CheckIncludeFiles)

# set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# set(CMAKE_INSTALL_PREFIX "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# enable_testing()

# find_package(CopperSpice REQUIRED)

# add_subdirectory(interface)

# message("CMAKE_C_COMPILER:          ${CMAKE_C_COMPILER}")
# message("CMAKE_CXX_COMPILER:        ${CMAKE_CXX_COMPILER}")

cmake_minimum_required(VERSION 3.16)
project(LogVisualizer)

include(CheckCXXCompilerFlag)
include(CheckCXXSourceCompiles)
include(CheckIncludeFile)
include(CheckIncludeFiles)

find_package(CopperSpice REQUIRED)
 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(GNUInstallDirs)
set(CMAKE_INSTALL_RPATH "\$ORIGIN")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
 
# location for building binary files
 
list(APPEND PROJECT_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
 
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
 
target_link_libraries(${PROJECT_NAME}
  PRIVATE
  CopperSpice::CsCore
  CopperSpice::CsGui
)
 
install(TARGETS ${PROJECT_NAME} DESTINATION .)

cs_copy_library(CsCore)
cs_copy_library(CsGui)
 
# installs the platform Gui plugin
cs_copy_plugins(CsGui)