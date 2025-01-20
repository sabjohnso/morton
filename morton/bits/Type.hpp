#pragma once

//
// ... Standard header files
//
#include <type_traits>

namespace morton::details {

  template <typename T>
  struct Type {
    using type = T;

    friend constexpr bool
    operator==(const Type &, const Type &) {
      return true;
    }

    template <typename U>
    friend constexpr bool
    operator==(const Type &, const Type<U> &) {
      return false;
    }

    template <typename U>
    friend constexpr bool
    operator!=(const Type &t1, const Type<U> &t2) {
      return !(t1 == t2);
    }
  };

  template <typename T>
  constexpr Type<std::remove_cvref_t<T>> type{};

} // end of namespace morton::details
