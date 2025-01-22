#pragma once

//
// ... Standard header files
//
#include <iostream>

namespace morton::details {

  /**
   * @brief A enumeration for specifying the orientation of a Morten encoding.
   *
   * @details The orientation values are given as `ROW_MAJOR` and `COLUMN_MAJOR`.
   * `ROW_MAJOR` offsets the second index first then the second index making a "Z" on a written
   * matrix layout. Hence the alternate name Morton order as Z order.  `COLUMN_MAJOR` offsets the
   * first index first, which would make a backward capital "N" on a written matrix layout.I follows
   * similarly for higher dimensional indexing.
   */
  enum class Orientation { ROW_MAJOR, COLUMN_MAJOR };

  /**
   * @brief A type acting as a compile-time specification of the encoding orientation
   */
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

    /**
     * @brief Inject a printable representation of the orientation into an output stream.
     */
    friend std::ostream &
    operator<<(std::ostream &os, const Orient &) {
      if constexpr (orientation == Orientation::ROW_MAJOR) {
        return os << "row_major";
      } else {
        return os << "column_major";
      }
    }
  };

  /**
   * @brief A template variable for specifying the orientation for Morton encoding
   */
  template <Orientation orientation>
  constexpr Orient<orientation> orient{};

  /**
   * @breif A variable specifying a row major orientation
   */
  constexpr Orient<Orientation::ROW_MAJOR> row_major{};

  /**
   * @brief A variable specifying a column major orientation
   */
  constexpr Orient<Orientation::COLUMN_MAJOR> column_major{};

} // end of namespace morton::details
