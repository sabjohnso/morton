#pragma once

//
// ... Standard header files
//
#include <iostream>

namespace morton::details {

  /**
   * @brief An enumeration for specifying the direction for shifting bits
   */
  enum class Direction { LEFT, RIGHT };

  /**
   * @brief A type acting as a compile-time specification of shift direction
   */
  template <Direction D>
  struct Dir {
    static constexpr Direction dir{D};

    /**
     * @brief Print a readable representation of the shift direction
     */
    friend std::ostream &
    operator<<(std::ostream &os, const Dir &) {
      if constexpr (D == Direction::LEFT) {
        return os << "left";
      } else {
        return os << "right";
      }
    }
  };

  /**
   * @brief A variable template for specifying shift direction
   */
  template <Direction D>
  constexpr Dir<D> dir{};

  /**
   * @brief A variable specifying left shifting of bits
   */
  constexpr Dir<Direction::LEFT> left{};

  /**
   * @brief A variable specifying right shifting of bits
   */
  constexpr Dir<Direction::RIGHT> right{};

} // end of namespace morton::details
