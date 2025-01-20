#pragma once

//
// ... Standard header files
//
#include <iostream>

namespace morton::details {

  enum class Direction { LEFT, RIGHT };

  template <Direction D>
  struct Dir {
    static constexpr Direction dir{D};

    friend std::ostream &
    operator<<(std::ostream &os, const Dir &) {
      if constexpr (D == Direction::LEFT) {
        return os << "left";
      } else {
        return os << "right";
      }
    }
  };

  template <Direction D>
  constexpr Dir<D> dir{};

  constexpr Dir<Direction::LEFT> left{};
  constexpr Dir<Direction::RIGHT> right{};

} // end of namespace morton::details
