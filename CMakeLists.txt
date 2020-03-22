cmake_minimum_required(VERSION 3.12)
project(poc)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR OR EXISTS "${CMAKE_BINARY_DIR}/CMakeLists.txt")
  message(FATAL_ERROR "In-source builds are not allowed.")
endif()

if(NOT WIN32)
  message(FATAL "This project targets Windows")
endif()

# windows.winmd search path
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -AI\"C:/Program Files (x86)/Windows Kits/10/UnionMetadata/10.0.17763.0\"" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -AI\"C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/Common7/IDE/VC/vcpackages\"" )

set(CMAKE_CXX_STANDARD 17)
add_compile_options("/ZW")

file(GLOB SOURCES "./src/*")
add_library(poc SHARED ${SOURCES})
