add_library("${LIB_NAME}"
  PID.cpp
)

target_include_directories("${LIB_NAME}" PUBLIC ../include)
target_compile_features("${LIB_NAME}" PUBLIC cxx_std_11)