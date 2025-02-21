configure_file(config.hpp.in config.hpp)

add_library(morton_header INTERFACE)
set_target_properties(morton_header PROPERTIES EXPORT_NAME header)
target_include_directories(morton_header
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${morton_INSTALL_INCLUDEDIR}>)

add_library(morton::header ALIAS morton_header)

add_library(morton_capi capi.cpp)
target_link_libraries(morton_capi PRIVATE morton::header)
set_target_properties(morton_capi
  PROPERTIES
  CXX_STANDARD ${morton_CXX_STANDARD}
  EXPORT_NAME capi
)

add_library(morton::capi ALIAS morton_capi)

install(TARGETS morton_header morton_capi
  EXPORT morton_EXPORTS
  RUNTIME DESTINATION ${morton_INSTALL_BINDIR}
  LIBRARY DESTINATION ${morton_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${morton_INSTALL_LIBDIR})

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  DESTINATION ${morton_INSTALL_INCLUDEDIR}/morton)
