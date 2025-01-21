#pragma once

//
// ... morton header files
//
#include <morton/bits/Mask.hpp>
#include <morton/bits/Natural.hpp>
#include <morton/bits/Simple_Permutation.hpp>
#include <morton/bits/Type.hpp>
#include <morton/bits/concepts.hpp>
#include <morton/bits/utility.hpp>

//
// ... Standard header files
//
#include <iostream>
#include <tuple>

namespace morton::details {

  template <typename... Permutations>
  struct Permutation_Sequence {
    static constexpr std::tuple<Permutations...> parts{};

    constexpr Permutation_Sequence(auto &&...){};

    template <concepts::integral T>
    constexpr auto
    operator()(const T &value) const {
      constexpr auto recur =
          []<unsigned_type Iter>(const auto recur, const Natural<Iter>, const auto value) {
            if constexpr (Iter == sizeof...(Permutations)) {
              return value;
            } else {
              return recur(recur, natural<Iter + 1>, std::get<Iter>(parts)(value));
            }
          };
      return recur(recur, natural<0>, std::make_signed_t<T>(value));
    }

    template <std::integral T, std::integral U>
    constexpr auto
    operator()(const T &value, const Type<U>) const {
      constexpr auto recur =
          []<unsigned_type Iter>(const auto recur, const Natural<Iter>, const auto value) {
            if constexpr (Iter == sizeof...(Permutations)) {
              return value;
            } else {
              return recur(recur, natural<Iter + 1>, std::get<Iter>(parts)(value, type<U>));
            }
          };
      return recur(recur, natural<0>, std::make_signed_t<T>(value));
    }

    friend std::ostream &
    operator<<(std::ostream &os, const Permutation_Sequence &sequence) {
      if constexpr (sizeof...(Permutations) == 0) {
        os << "Permutation_Sequence{}";
      } else {
        os << "Permutation_Sequence{" << std::get<0>(sequence.parts);
        [&]<std::size_t... i>(std::index_sequence<i...>) {
          ((os << "," << std::get<i + 1>(sequence.parts)), ...);
        }
        (std::make_index_sequence<sizeof...(Permutations) - 1>());
        os << "}";
      }
      return os;
    }
  };

  template <typename... Permutations>
  Permutation_Sequence(Permutations &&...)
      -> Permutation_Sequence<std::remove_cvref_t<Permutations>...>;

  template <typename... Permutations>
  constexpr bool
  conservative(Permutation_Sequence<Permutations...>) {
    using Permutation_Type = Permutation_Sequence<Permutations...>;
    if constexpr (sizeof...(Permutations) > 0) {
      return (conservative(Permutations{}) && ...) &&
             static_cast<unsigned_type>(std::popcount(
                 Permutation_Type{}(domain_bits(utility::first(Permutations{}...))))) ==
                 num_bits(utility::first(Permutations{}...));
    } else {
      return true;
    }
  }

  template <unsigned_type N>
  struct Bits_Per_Index {};

  template <unsigned_type N>
  constexpr Bits_Per_Index<N> bits_per_index{};

  template <unsigned_type N>
  struct Num_Indices {};

  template <unsigned_type N>
  constexpr Num_Indices<N> num_indices{};

  template <unsigned_type N>
  constexpr Mask<(1u << (N / 2u)) - 1u>
  make_hold_mask(const Bits_Per_Index<N> &) {
    return {};
  }

  template <typename... Permutations>
  constexpr auto
  domain_bits(Permutation_Sequence<Permutations...>) {
    if constexpr (sizeof...(Permutations) > 0) {
      return domain_bits(utility::first(Permutations{}...));
    } else {
      return ~0UL;
    }
  }

  template <typename... Permutations>
  constexpr auto
  codomain_bits(const Permutation_Sequence<Permutations...> &permutation) {
    if constexpr (sizeof...(Permutations) > 0) {
      return permutation(domain_bits(permutation));
    } else {
      return ~0UL;
    }
  }

  template <unsigned_type M, unsigned_type N>
  constexpr Mask<((1UL << (M / 2UL)) - 1UL) << ((M / 2UL) * N)>
  make_contraction_shift_mask(const Bits_Per_Index<M> &, Num_Indices<N>) {
    return {};
  }

  template <unsigned_type M, unsigned_type N>
  constexpr auto
  make_contraction_masks(Bits_Per_Index<M>, Num_Indices<N>) {
    constexpr auto recur = []<unsigned_type MIter>(
                               const auto recur, Bits_Per_Index<MIter>, auto &&...permutations) {
      if constexpr (MIter > M) {
        return Permutation_Sequence{permutations...};
      } else {
        return recur(recur,
                     bits_per_index<2UL * MIter>,
                     duplicate(permutations)...,
                     Simple_Permutation{
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

  template <unsigned_type N>
  constexpr Mask<((1u << (N / 2u)) - 1) << (N / 2u)>
  make_expansion_shift_mask(const Bits_Per_Index<N> &) {
    return {};
  }

  template <unsigned_type M, unsigned_type N>
  constexpr auto
  make_expansion_masks(Bits_Per_Index<M>, Num_Indices<N>) {
    constexpr auto recur =
        []<unsigned_type MIter>(const auto recur, Bits_Per_Index<MIter>, auto &&...permutations) {
          if constexpr (MIter > M) {
            return Permutation_Sequence{permutations...};
          } else {
            return recur(recur,
                         bits_per_index<2 * MIter>,
                         Simple_Permutation{
                             .size = natural<MIter * N>,
                             .dist = shift<(MIter * (N - 1)) / 2>,
                             .dir = left,
                             .move = make_expansion_shift_mask(bits_per_index<MIter>),
                             .hold = make_hold_mask(bits_per_index<MIter>),
                         },
                         duplicate(permutations)...);
          }
        };
    return recur(recur, bits_per_index<2u>);
  }

} // end of namespace morton::details

namespace std {

  template <typename... Permutations>
  constexpr auto
  get(const morton::details::Permutation_Sequence<Permutations...> &) {
    get(morton::details::Permutation_Sequence<Permutations...>::parts);
  }

} // end of namespace std
