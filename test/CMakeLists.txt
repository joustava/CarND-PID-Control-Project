cmake_minimum_required(VERSION 3.19)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.3
)
FetchContent_MakeAvailable(Catch2)

add_executable(${TEST_LIB_NAME}
  support.cpp
  PID_test.cpp
  # add tests
)

target_compile_features(${TEST_LIB_NAME} PRIVATE cxx_std_17)

target_link_libraries(${TEST_LIB_NAME} PRIVATE "${LIB_NAME}" Catch2::Catch2)