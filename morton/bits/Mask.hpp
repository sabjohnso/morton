#pragma once

//
// ... morton header files
//
#include <morton/bits/base_types.hpp>

//
// ... Standard header files
//
#include <bitset>
#include <concepts>
#include <iostream>

namespace morton::details {

  template <unsigned_type N>
  struct Mask {
    static constexpr unsigned_type value{N};

    friend constexpr bool
    operator==(const Mask &, const Mask &) {
      return true;
    }

    template <unsigned_type M>
    friend constexpr bool
    operator==(const Mask &, const Mask<M> &) {
      return false;
    }

    template <unsigned_type M>
    friend constexpr bool
    operator!=(const Mask &n, const Mask<M> &m) {
      return !(n == m);
    }

    template <unsigned_type M>
    friend constexpr Mask<N & M>
    operator&(const Mask &, const Mask<M> &) {
      return {};
    }

    template <unsigned_type M>
    friend constexpr Mask<N | M>
    operator&(const Mask &, const Mask<M> &) {
      return {};
    }

    template <unsigned_type M>
    friend constexpr Mask<N ^ M>
    operator&(const Mask &, const Mask<M> &) {
      return {};
    }

    template <unsigned_type M>
    friend constexpr Mask<~M>
    operator~(const Mask &) {
      return {};
    }

    constexpr auto
    operator()(std::integral auto arg) const {
      return arg & N;
    }

    friend std::ostream &
    operator<<(std::ostream &os, const Mask &) {
      return os << "mask<" << std::bitset<sizeof(N)>{N} << ">";
    }
  };

  template <unsigned_type N>
  constexpr Mask<N> mask{};

} // end of namespace morton::details
