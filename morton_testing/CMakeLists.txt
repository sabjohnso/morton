find_package(Catch2 REQUIRED)

macro(morton_add_test test_name)
  set(exe_name ${test_name}_test)
  set(src_name ${exe_name}.cpp)
  add_executable(${exe_name} ${src_name})
  target_link_libraries(${exe_name} PRIVATE
    morton::header
    morton::capi
    Catch2::Catch2WithMain)
  set_target_properties(${exe_name}
    PROPERTIES
    CXX_STANDARD ${morton_CXX_STANDARD})
  add_test(${test_name} ${exe_name})
endmacro()

morton_add_test(simple_permutation)
morton_add_test(expansion_masks)
morton_add_test(contraction_masks)
morton_add_test(utility)
morton_add_test(encoder)
morton_add_test(decoder)
morton_add_test(capi)
