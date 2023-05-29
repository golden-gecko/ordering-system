cmake_minimum_required(VERSION 3.26)

project(ordering-system)

add_executable(ordering-system Customer.cpp Main.cpp Order.cpp Product.cpp)

set_target_properties(ordering-system PROPERTIES
    CXX_EXTENSIONS NO
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
