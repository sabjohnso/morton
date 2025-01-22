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
   * @tparam Dir  Specification of the direction the bits will be shifted
   * @tparam Move Specification of the bits that will be moved
   * @tparam Hold Specification of the bits that will not move (the remaining are zeroed).
   *
   * @details All fields in the `Simple_Permutation` type are empty
   * types and merly provide documented configuration, on construction
   * of the type and when printing the type.
   */
  template <typename Size, typename Dist, typename Dir, typename Move, typename Hold>
  struct Simple_Permutation {
    Size size{};
    Dist dist{};
    Dir dir{};
    Move move{};
    Hold hold{};

    /**
     * @brief Apply the permutation to the bits of the input value.
     */
    template <concepts::integral T>
    constexpr concepts::unsigned_integral auto
    operator()(const T &input) const {
      return dist(move(input), dir) + hold(input);
    }

    /**
     * @brief Apply the permutation of the bits of the input value
     * cast as the type in the type specification argument.
     */
    template <concepts::integral T, concepts::unsigned_integral U>
    constexpr concepts::unsigned_integral auto
    operator()(const T &input, Type<U>) const {
      return U(dist(move(U(input)), dir) + hold(U(input)));
    }

    /**
     * @brief Write a readable representation of of the permutation to
     * the output stream.
     */
    friend std::ostream &
    operator<<(std::ostream &os, const Simple_Permutation &permutation) {
      return os << "Simple_Permutation{"
                << ".size=" << permutation.size << ","
                << ".dist=" << permutation.dist << ","
                << ".dir=" << permutation.dir << ","
                << ".move=" << permutation.move << ","
                << ".hold=" << permutation.hold << "}";
    }
  };

  template <unsigned_type Size,
            unsigned_type Dist,
            Direction dir,
            unsigned_type Move,
            unsigned_type Hold>
  Simple_Permutation(Natural<Size>, Shift<Dist>, Dir<dir>, Mask<Move>, Mask<Hold>)
      -> Simple_Permutation<Natural<Size>, Shift<Dist>, Dir<dir>, Mask<Move>, Mask<Hold>>;

  /**
   * @brief Return a permutation that has twice the size as the input
   * permutation and duplicated bit patterns.
   */
  template <unsigned_type size,
            unsigned_type dist,
            Direction dir,
            unsigned_type move,
            unsigned_type hold>
  constexpr auto
  duplicate(
      const Simple_Permutation<Natural<size>, Shift<dist>, Dir<dir>, Mask<move>, Mask<hold>> &) {
    return Simple_Permutation{
        .size = natural<2 * size>,
        .dist = shift<dist>,
        .dir = Dir<dir>{},
        .move = mask<move + (move << size)>,
        .hold = mask<hold + (hold << size)>,
    };
  }

  /**
   * @brief A predicate returning true if neither the domain or
   * codomain of the `move` bit set intersect with the `hold` bit set.
   *
   * @details This is an important aspect of bit conserving
   * permutations: if either the domain or codomain intersect with the
   * `hold` bit set, bit will either be duplicated or destroyed,
   * losing information.
   */
  template <unsigned_type size,
            unsigned_type dist,
            Direction dir,
            unsigned_type move,
            unsigned_type hold>
  constexpr bool
  partitioned(
      const Simple_Permutation<Natural<size>, Shift<dist>, Dir<dir>, Mask<move>, Mask<hold>> &) {
    return (move & hold) == 0u;
  }

  /**
   * @brief A predicate on permutations that returns true if the
   * permutation conserves bits, and false otherwise.
   */
  template <unsigned_type size,
            unsigned_type dist,
            Direction dir,
            unsigned_type move,
            unsigned_type hold>
  constexpr bool
  conservative(
      const Simple_Permutation<Natural<size>, Shift<dist>, Dir<dir>, Mask<move>, Mask<hold>>
          &permutation) {
    return partitioned(permutation) && ((permutation(move) & hold) == 0u);
  }

  /**
   * @brief Return the number of bits handled by the permuation: the
   * population count of the move and hold masks
   */
  template <unsigned_type size,
            unsigned_type dist,
            Direction dir,
            unsigned_type move,
            unsigned_type hold>
  constexpr unsigned_type
  num_bits(
      const Simple_Permutation<Natural<size>, Shift<dist>, Dir<dir>, Mask<move>, Mask<hold>> &) {
    using Permutation_Type =
        Simple_Permutation<Natural<size>, Shift<dist>, Dir<dir>, Mask<move>, Mask<hold>>;
    static_assert(conservative(Permutation_Type{}));
    return std::popcount(move) + std::popcount(hold);
  }

  /**
   * @brief Return the input bits for the permuation
   */
  template <unsigned_type size,
            unsigned_type dist,
            Direction dir,
            unsigned_type move,
            unsigned_type hold>
  constexpr unsigned_type
  domain_bits(
      const Simple_Permutation<Natural<size>, Shift<dist>, Dir<dir>, Mask<move>, Mask<hold>> &) {
    return move | hold;
  }

  /**
   * @brief Return the output bits for the permutation
   */
  template <unsigned_type size,
            unsigned_type dist,
            Direction dir,
            unsigned_type move,
            unsigned_type hold>
  constexpr unsigned_type
  codomain_bits(
      const Simple_Permutation<Natural<size>, Shift<dist>, Dir<dir>, Mask<move>, Mask<hold>>
          &permutation) {
    return permutation(domain_bits(permutation));
  }

} // end of namespace morton::details
