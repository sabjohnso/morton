#pragma once

//
// ... Standard header files
//
#include <concepts>
#include <type_traits>

namespace morton::concepts {

  using std::integral;

  template <typename T>
  concept unsigned_integral = std::integral<T> && std::is_unsigned_v<T>;

} // end of namespace morton::concepts
