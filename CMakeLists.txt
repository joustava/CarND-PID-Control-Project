cmake_minimum_required (VERSION 3.5)

# project info
project(pid
  VERSION 0.0.1
  DESCRIPTION "PID Controller"
  LANGUAGES CXX
)

# create target variables
set(APP_NAME ${PROJECT_NAME})
set(LIB_NAME ${PROJECT_NAME}_lib)
set(TEST_LIB_NAME ${LIB_NAME}_test)

# set build flags
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

# set ./bin as output dir for binaries 
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin) 
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# extra householding needed when on Mac
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 

include_directories(/usr/local/include)
include_directories(/usr/local/opt/openssl/include)
link_directories(/usr/local/lib)
link_directories(/usr/local/opt/openssl/lib)
link_directories(/usr/local/Cellar/libuv/1*/lib)

endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 

# include CMakeList rules for lib, test and app targets.
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(app)
