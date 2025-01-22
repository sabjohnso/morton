#pragma once

//
// ... morton header files
//
#include <morton/bits/Orientation.hpp>
#include <morton/bits/Permutation_Sequence.hpp>

//
// ... Standard header files
//
#include <array>

namespace morton::details {

  /**
   * @brief A type describing the decoding of Morton indices for a specified number of indices and
   * orientation.
   */
  template <typename Num_Indices, typename Orientation, typename Permutation>
  struct Decoder {

    Num_Indices ndims{};
    Orientation orient{};
    Permutation permutation{};

    template <unsigned_type I, std::integral T>
    constexpr auto
    operator()(Natural<I>, const T &index) const {
      constexpr unsigned_type N = Num_Indices::value;
      static_assert(I < N);
      if constexpr (Orientation{} == row_major) {
        return permutation(index >> (N - I - 1UL));
      } else {
        return permutation(index >> I);
      }
    }

    template <std::integral T>
    constexpr auto
    operator()(const T index) const {
      constexpr unsigned_type N = Num_Indices::value;
      return [&, this ]<std::size_t... I>(std::index_sequence<I...>) {
        return std::array{(*this)(natural<I>, index)...};
      }
      (std::make_index_sequence<N>());
    }
  };

  template <typename Num_Indices, typename Orientation, typename Permutation>
  Decoder(const Num_Indices &, const Orientation &, const Permutation &)
      -> Decoder<Num_Indices, Orientation, Permutation>;

  /**
   * @brief Return a decoder configured according tot the inputs.
   */
  template <unsigned_type M, unsigned_type N, Orientation orientation>
  constexpr auto
  make_decoder(Bits_Per_Index<M>, Num_Indices<N>, Orient<orientation>) {
    return Decoder{
        .ndims = Natural<N>{},
        .orient = Orient<orientation>{},
        .permutation = make_contraction_masks(bits_per_index<M>, num_indices<N>),
    };
  }

} // namespace morton::details
