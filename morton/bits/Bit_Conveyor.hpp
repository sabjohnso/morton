#pragma once

//
// ... Morton header files
//
#include <morton/bits/Direction.hpp>
#include <morton/bits/Mask.hpp>
#include <morton/bits/Natural.hpp>
#include <morton/bits/Shift.hpp>
#include <morton/bits/Type.hpp>
#include <morton/bits/base_types.hpp>
#include <morton/bits/concepts.hpp>

//
// ... Standard header files
//
#include <bit>
#include <concepts>
#include <iostream>

namespace morton::details {

  /**
   * @brief A type describing an a transformation of bits, where some bits are
   * shifted by a specified distance, other bits are held in their original position
   * and the remaining bits are removed (zeroed).
   *
   * @tparam Size Specification of the extent in bits of the operation
   * @tparam Dist Specification of the distance bits will be shifted
   * @tparam Move Specification of the bits that will be moved
   * @tparam Hold Specification of the bits that will not move (the remaining are zeroed).
   */
  template <typename Size, typename Dist, typename Dir, typename Move, typename Hold>
  struct Bit_Conveyor {
    Size size{};
    Dist dist{};
    Dir dir{};
    Move move{};
    Hold hold{};

    template <concepts::integral T>
    constexpr concepts::unsigned_integral auto
    operator()(const T &input) const {
      return dist(move(input), dir) + hold(input);
    }

    template <concepts::integral T, concepts::unsigned_integral U>
    constexpr concepts::unsigned_integral auto
    operator()(const T &input, Type<U>) const {
      return U(dist(move(U(input)), dir) + hold(U(input)));
    }

    friend std::ostream &
    operator<<(std::ostream &os, const Bit_Conveyor &conveyor) {
      return os << "Bit_Conveyor{"
                << ".size=" << conveyor.size << ","
                << ".dist=" << conveyor.dist << ","
                << ".dir=" << conveyor.dir << ","
                << ".move=" << conveyor.move << ","
                << ".hold=" << conveyor.hold << "}";
    }
  };

  template <unsigned_type Size,
            signed_type Dist,
            Direction dir,
            unsigned_type Move,
            unsigned_type Hold>
  Bit_Conveyor(Natural<Size>, Shift<Dist>, Dir<dir>, Mask<Move>, Mask<Hold>)
      -> Bit_Conveyor<Natural<Size>, Shift<Dist>, Dir<dir>, Mask<Move>, Mask<Hold>>;

  template <unsigned_type size,
            signed_type dist,
            Direction dir,
            unsigned_type move,
            unsigned_type hold>
  constexpr auto
  duplicate(const Bit_Conveyor<Natural<size>, Shift<dist>, Dir<dir>, Mask<move>, Mask<hold>> &) {
    return Bit_Conveyor{
        .size = natural<2 * size>,
        .dist = shift<dist>,
        .dir = Dir<dir>{},
        .move = mask<move + (move << size)>,
        .hold = mask<hold + (hold << size)>,
    };
  }

  template <unsigned_type size,
            signed_type dist,
            Direction dir,
            unsigned_type move,
            unsigned_type hold>
  constexpr bool
  partitioned(const Bit_Conveyor<Natural<size>, Shift<dist>, Dir<dir>, Mask<move>, Mask<hold>> &) {
    return (move & hold) == 0u;
  }

  template <unsigned_type size,
            signed_type dist,
            Direction dir,
            unsigned_type move,
            unsigned_type hold>
  constexpr bool
  conservative(
      const Bit_Conveyor<Natural<size>, Shift<dist>, Dir<dir>, Mask<move>, Mask<hold>> &conveyor) {
    return partitioned(conveyor) && ((conveyor(move) & hold) == 0u);
  }

  template <unsigned_type size,
            signed_type dist,
            Direction dir,
            unsigned_type move,
            unsigned_type hold>
  constexpr unsigned_type
  num_bits(const Bit_Conveyor<Natural<size>, Shift<dist>, Dir<dir>, Mask<move>, Mask<hold>> &) {
    using Conveyor_Type =
        Bit_Conveyor<Natural<size>, Shift<dist>, Dir<dir>, Mask<move>, Mask<hold>>;
    static_assert(conservative(Conveyor_Type{}));
    return std::popcount(move) + std::popcount(hold);
  }

  template <unsigned_type size,
            signed_type dist,
            Direction dir,
            unsigned_type move,
            unsigned_type hold>
  constexpr unsigned_type
  bits(const Bit_Conveyor<Natural<size>, Shift<dist>, Dir<dir>, Mask<move>, Mask<hold>> &) {
    return move | hold;
  }

} // end of namespace morton::details
