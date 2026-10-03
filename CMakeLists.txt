cmake_minimum_required(VERSION 3.28)

project(explain)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(explain)

target_sources(explain
    PRIVATE
        explain.cpp
)

target_link_libraries(explain
    PRIVATE
        query
        flags
)

add_subdirectory(query)
add_subdirectory(flags)

include(GNUInstallDirs)
install(TARGETS explain DESTINATION ${CMAKE_INSTALL_BINDIR})
