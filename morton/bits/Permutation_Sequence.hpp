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

  template <typename... Conveyors>
  struct Conveyor_Sequence {
    static constexpr std::tuple<Conveyors...> parts{};

    constexpr Conveyor_Sequence(auto &&...){};

    template <concepts::integral T>
    constexpr auto
    operator()(const T &value) const {
      constexpr auto recur =
          []<unsigned_type Iter>(const auto recur, const Natural<Iter>, const auto value) {
            if constexpr (Iter == sizeof...(Conveyors)) {
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
            if constexpr (Iter == sizeof...(Conveyors)) {
              return value;
            } else {
              return recur(recur, natural<Iter + 1>, std::get<Iter>(parts)(value, type<U>));
            }
          };
      return recur(recur, natural<0>, std::make_signed_t<T>(value));
    }

    friend std::ostream &
    operator<<(std::ostream &os, const Conveyor_Sequence &sequence) {
      if constexpr (sizeof...(Conveyors) == 0) {
        os << "Conveyor_Sequence{}";
      } else {
        os << "Conveyor_Sequence{" << std::get<0>(sequence.parts);
        [&]<std::size_t... i>(std::index_sequence<i...>) {
          ((os << "," << std::get<i + 1>(sequence.parts)), ...);
        }
        (std::make_index_sequence<sizeof...(Conveyors) - 1>());
        os << "}";
      }
      return os;
    }
  };

  template <typename... Conveyors>
  Conveyor_Sequence(Conveyors &&...) -> Conveyor_Sequence<std::remove_cvref_t<Conveyors>...>;

  template <typename... Conveyors>
  constexpr bool
  conservative(Conveyor_Sequence<Conveyors...>) {
    using Conveyor_Type = Conveyor_Sequence<Conveyors...>;
    if constexpr (sizeof...(Conveyors) > 0) {
      return (conservative(Conveyors{}) && ...) &&
             std::popcount(Conveyor_Type{}(domain_bits(utility::first(Conveyors{}...)))) ==
                 num_bits(utility::first(Conveyors{}...));
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

  template <typename... Conveyors>
  constexpr auto
  domain_bits(Conveyor_Sequence<Conveyors...>) {
    if constexpr (sizeof...(Conveyors) > 0) {
      return domain_bits(utility::first(Conveyors{}...));
    } else {
      return ~0UL;
    }
  }

  template <typename... Conveyors>
  constexpr auto
  codomain_bits(const Conveyor_Sequence<Conveyors...> &conveyor) {
    if constexpr (sizeof...(Conveyors) > 0) {
      return conveyor(domain_bits(conveyor));
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

namespace std {

  template <typename... Conveyors>
  constexpr auto
  get(const morton::details::Conveyor_Sequence<Conveyors...> &) {
    get(morton::details::Conveyor_Sequence<Conveyors...>::parts);
  }

} // end of namespace std
