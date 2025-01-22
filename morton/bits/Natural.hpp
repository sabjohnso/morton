#pragma once

//
// ... morton header files
//
#include <morton/bits/base_types.hpp>

//
// ... Standard header files
//
#include <iostream>

namespace morton::details {

  /**
   * @brief A compile-time unsigned integer.
   */
  template <unsigned_type N>
  struct Natural {
    static constexpr unsigned_type value{N};

    friend constexpr bool
    operator==(const Natural &, const Natural &) {
      return true;
    }

    template <unsigned_type M>
    friend constexpr bool
    operator==(const Natural &, const Natural<M> &) {
      return false;
    }

    template <unsigned_type M>
    friend constexpr bool
    operator!=(const Natural &n, const Natural<M> &m) {
      return !(n == m);
    }
    friend std::ostream &
    operator<<(std::ostream &os, const Natural &) {
      return os << "natural<" << N << ">";
    }
  };

  template <unsigned_type N>
  constexpr Natural<N> natural{};

} // end of namespace morton::details
