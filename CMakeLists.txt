cmake_minimum_required(VERSION 3.12)

project(morton VERSION 0.1.0 LANGUAGES C CXX)

option(morton_BUILD_TESTING "Build the morton tests" ON)
set(morton_CXX_STANDARD 20 CACHE STRING "C++ standard for morton")

include(GNUInstallDirs)
set(morton_INSTALL_BINDIR ${CMAKE_INSTALL_BINDIR})
set(morton_INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR})
set(morton_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR})
set(morton_INSTALL_CONFDIR ${morton_INSTALL_LIBDIR}/cmake/morton-${PROJECT_VERSION})

list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)
include(morton_deps)

add_subdirectory(morton)

if(morton_BUILD_TESTING)
  include(CTest)
  if(BUILD_TESTING)
    add_subdirectory(morton_testing)
  endif()
endif()

install(EXPORT morton_EXPORTS
  NAMESPACE morton::
  FILE morton-exports.cmake
  DESTINATION ${morton_INSTALL_CONFDIR})

configure_file(morton-config.cmake.in morton-config.cmake)
install(FILES ${PROJECT_BINARY_DIR}/morton-config.cmake
  DESTINATION ${morton_INSTALL_CONFDIR})
