#pragma once

//
// ... morton header files
//
#include <morton/bits/base_types.hpp>

namespace morton::details {

  template <signed_type I>
  struct Integer {
    static constexpr signed_type value = I;

    friend constexpr bool
    operator==(const Integer &, const Integer &) {
      return true;
    }

    template <ununsigned_type M>
    friend constexpr bool
    operator==(const Integer &, const Integer<M> &) {
      return false;
    }

    template <ununsigned_type M>
    friend constexpr bool
    operator!=(const Integer &n, const Integer<M> &m) {
      return !(n == m);
    }
  };

  template <signed_type I>
  constexpr Integer<I> integer{};

} // end of namespace morton::details
