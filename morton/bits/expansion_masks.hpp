#pragma once

//
// ... matmul header files
//
#include <morton/bits/Bit_Conveyor.hpp>
#include <morton/bits/Conveyor_Sequence.hpp>

namespace morton::details {

  template <unsigned_type N>
  constexpr Mask<((1u << (N / 2u)) - 1) << (N / 2u)>
  make_expansion_shift_mask(const Bits_Per_Index<N> &) {
    return {};
  }

  template <unsigned_type M, unsigned_type N>
  constexpr auto
  make_expansion_masks(Bits_Per_Index<M>, Num_Indices<N>) {
    constexpr auto recur =
        []<unsigned_type MIter>(const auto recur, Bits_Per_Index<MIter>, auto &&...conveyors) {
          if constexpr (MIter > M) {
            return Conveyor_Sequence{conveyors...};
          } else {
            return recur(recur,
                         bits_per_index<2 * MIter>,
                         Bit_Conveyor{
                             .size = natural<MIter * N>,
                             .dist = shift<(MIter * (N - 1)) / 2>,
                             .dir = left,
                             .move = make_expansion_shift_mask(bits_per_index<MIter>),
                             .hold = make_hold_mask(bits_per_index<MIter>),
                         },
                         duplicate(conveyors)...);
          }
        };
    return recur(recur, bits_per_index<2u>);
  }

} // end of namespace morton::details
