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
#include <iostream>

namespace morton::details {

  /**
   * @brief A type describing the encoding of indices with a Morton index for a specified number of
   * indices and orientation.
   */
  template <typename Num_Indices, typename Orientation, typename Permutation>
  struct Encoder {

    Num_Indices ndims{};
    Orientation orient{};
    Permutation permutation{};

    /**
     * @brief Encode input indices.
     */
    template <std::integral... Ts>
    constexpr auto
    operator()(const Ts... indices) const {
      constexpr unsigned_type N = Num_Indices::value;
      static_assert(sizeof...(Ts) == Num_Indices::value);
      return [&, this ]<std::size_t... i>(std::index_sequence<i...>, const auto &indices) {
        if constexpr (Orientation{} == row_major) {
          return ((permutation(indices[i]) << (N - i - 1UL)) + ...);
        } else {
          return ((permutation(indices[i]) << i) + ...);
        }
      }
      (std::make_index_sequence<N>(), std::array{indices...});
    }

    /**
     * @brief Inject a readable representation of the Encoder into the output stream.
     */
    friend std::ostream &
    operator<<(std::ostream &os, const Encoder &encoder) {
      return os << "Encoder{.ndims=" << encoder.ndims << ","
                << ".orient=" << encoder.orient << ","
                << ".permutation=" << encoder.permutation << "}";
    }
  };

  template <typename Num_Indices, typename Orientation, typename Permutation>
  Encoder(const Num_Indices &, const Orientation &, const Permutation &)
      -> Encoder<Num_Indices, Orientation, Permutation>;

  /**
   * @brief Return an encoder configured according to the inputs.
   */
  template <unsigned_type M, unsigned_type N, Orientation orientation>
  constexpr auto
  make_encoder(Bits_Per_Index<M>, Num_Indices<N>, Orient<orientation>) {
    return Encoder{
        .ndims = Natural<N>{},
        .orient = Orient<orientation>{},
        .permutation = make_expansion_masks(bits_per_index<M>, num_indices<N>),
    };
  }

} // namespace morton::details
