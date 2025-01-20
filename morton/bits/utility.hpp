#pragma once

//
// ... morton header files
//
#include <morton/bits/base_types.hpp>

//
// ... standard header files
//
#include <bit>
#include <concepts>

namespace morton::utility {
  using morton::details::unsigned_type;

  constexpr unsigned_type bits_per_byte{8};

  constexpr bool
  even(std::integral auto n) {
    return n % 2 == 0;
  }

  constexpr bool
  odd(std::integral auto n) {
    return !even(n);
  }

  constexpr auto
  ilog2(std::integral auto n) {
    return bits_per_byte * sizeof(n) - std::countl_zero(n) - 1u;
  }

  template <typename T, typename... Ts>
  constexpr auto
  first(T &&x, Ts &&...) {
    return x;
  }

} // namespace morton::utility
