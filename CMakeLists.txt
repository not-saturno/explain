cmake_minimum_required(VERSION 3.28)

project(explain)

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


set(VERSION "1.0.0")
set(CPACK_PACKAGE_NAME "explain")
set(CPACK_PACKAGE_VERSION ${VERSION})
set(CPACK_RPM_PACKAGE_RELEASE_DIST ON)
set(CPACK_GENERATOR "RPM")
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_PACKAGE_CONTACT "Saturno")
set(CPACK_PACKAGE_VENDOR "Saturno")
set(CPACK_RPM_PACKAGE_DESCRIPTION
    "Fast command-line utility designed for terminal workflow automation and API querying.")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_PACKAGE_RELEASE}.${CMAKE_SYSTEM_PROCESSOR}")
set(CPACK_PACKAGING_INSTALL_PREFIX "/usr")
set(CPACK_RPM_PACKAGE_SOURCES ON)

set(CPACK_RPM_BUILDREQUIRES
    "cmake, gcc-c++, make, cpr-devel, json-devel"
)

include(CPack)

