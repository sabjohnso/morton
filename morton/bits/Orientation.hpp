#pragma once

//
// ... Standard header files
//
#include <iostream>

namespace morton::details {

  enum class Orientation { ROW_MAJOR, COLUMN_MAJOR };

  template <Orientation orientation>
  struct Orient {

    template <Orientation other_orientation>
    friend constexpr bool
    operator==(const Orient &, const Orient<other_orientation> &) {
      return orientation == other_orientation;
    }

    template <Orientation other_orientation>
    friend constexpr bool
    operator!=(const Orient &orient1, const Orient<other_orientation> &orient2) {
      return !(orient1 == orient2);
    }

    friend std::ostream &
    operator<<(std::ostream &os, const Orient &) {
      if constexpr (orientation == Orientation::ROW_MAJOR) {
        return os << "row_major";
      } else {
        return os << "column_major";
      }
    }
  };

  template <Orientation orientation>
  constexpr Orient<orientation> orient{};

  constexpr Orient<Orientation::ROW_MAJOR> row_major{};
  constexpr Orient<Orientation::COLUMN_MAJOR> column_major{};

} // end of namespace morton::details
