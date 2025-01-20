#pragma once

//
// ... morton header files
//
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
             std::popcount(Conveyor_Type{}(bits(utility::first(Conveyors{}...)))) ==
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

} // end of namespace morton::details
