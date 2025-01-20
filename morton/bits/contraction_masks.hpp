#pragma once

//
// ... morton header files
//
#include <morton/bits/Conveyor_Sequence.hpp>

namespace morton::details {

  template <unsigned_type M, unsigned_type N>
  constexpr Mask<((1UL << (M / 2UL)) - 1UL) << ((M / 2UL) * N)>
  make_contraction_shift_mask(const Bits_Per_Index<M> &, Num_Indices<N>) {
    return {};
  }

  template <unsigned_type M, unsigned_type N>
  constexpr auto
  make_contraction_masks(Bits_Per_Index<M>, Num_Indices<N>) {
    constexpr auto recur = []<unsigned_type MIter>(
                               const auto recur, Bits_Per_Index<MIter>, auto &&...conveyors) {
      if constexpr (MIter > M) {
        return Conveyor_Sequence{conveyors...};
      } else {
        return recur(recur,
                     bits_per_index<2UL * MIter>,
                     duplicate(conveyors)...,
                     Bit_Conveyor{
                         .size = natural<MIter * N>,
                         .dist = shift<(signed_type(MIter) * (signed_type(N) - 1UL)) / 2UL>,
                         .dir = right,
                         .move = make_contraction_shift_mask(bits_per_index<MIter>, num_indices<N>),
                         .hold = make_hold_mask(bits_per_index<MIter>),
                     });
      }
    };
    return recur(recur, bits_per_index<2u>);
  }

} // end of namespace morton::details
