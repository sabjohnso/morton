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
   * @brief A compile-time unsigned integer for specifying the distance for shifting bits
   */
  template <unsigned_type I>
  struct Shift {
    static constexpr signed_type value = I;

    friend constexpr bool
    operator==(const Shift &, const Shift &) {
      return true;
    }

    template <signed_type M>
    friend constexpr bool
    operator==(const Shift &, const Shift<M> &) {
      return false;
    }

    template <signed_type M>
    friend constexpr bool
    operator!=(const Shift &n, const Shift<M> &m) {
      return !(n == m);
    }

    /**
     * @brief Shift bits to the left
     */
    constexpr auto
    operator()(std::integral auto arg, const Dir<Direction::LEFT> &) const {
      return arg << I;
    }

    /**
     * @brief Shift bits to the right
     */
    constexpr auto
    operator()(std::integral auto arg, const Dir<Direction::RIGHT> &) const {
      return arg >> I;
    }

    /**
     * @brief Print a readable representation of the shift specification
     */
    friend std::ostream &
    operator<<(std::ostream &os, const Shift &) {
      return os << "shift<" << I << ">";
    }
  };

  /**
   * @brief A variable template for specifying shift distance
   */
  template <signed_type I>
  constexpr Shift<I> shift{};

} // end of namespace morton::details
