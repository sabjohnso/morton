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

  template <signed_type I>
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

    constexpr auto
    operator()(std::integral auto arg) const {
      return arg << I;
    }

    friend std::ostream &
    operator<<(std::ostream &os, const Shift &) {
      return os << "shift<" << I << ">";
    }
  };

  template <signed_type I>
  constexpr Shift<I> shift{};

} // end of namespace morton::details
