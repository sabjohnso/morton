//
// ... morton header files
//
#include <morton/morton.hpp>

//
// ... Testing header files
//
#include <catch2/catch_test_macros.hpp>

namespace morton::testing {
  TEST_CASE("encoder") {

    SECTION("row major") {
      SECTION("2bits/index") {
        constexpr auto m = 2U;

        SECTION("2-dimensional") {
          constexpr auto ndims = 2U;
          constexpr auto encode = make_encoder(bits_per_index<m>, num_indices<ndims>, row_major);

          CHECK(encode(0b0000U, 0b0011U) == 0b0101U);
          CHECK(encode(0b0011U, 0b0000U) == 0b1010U);
          CHECK(encode(0b0011U, 0b0011U) == 0b1111U);
        }
      }

      SECTION("4bits/index") {}
    }

    SECTION("column major") {}
  }

} // end of namespace morton::testing
