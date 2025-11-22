cmake_minimum_required(VERSION 4.2)

project(ordering-system)

add_executable(
    ordering-system
    Customer.cpp Customer.hpp
    Main.cpp
    Order.cpp Order.hpp
    Product.cpp Product.hpp
)

set_target_properties(ordering-system PROPERTIES
    CXX_EXTENSIONS NO
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
