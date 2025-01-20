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
          constexpr auto decode = make_decoder(bits_per_index<m>, num_indices<ndims>, row_major);

          CHECK(decode(natural<0>, 0b0101U) == 0b0000U);
          CHECK(decode(natural<1>, 0b0101U) == 0b0011U);
          {
            const auto [i, j] = decode(0b0101U);
            CHECK(i == 0b0000U);
            CHECK(j == 0b0011U);
          }

          CHECK(decode(natural<0>, 0b1010U) == 0b0011U);
          CHECK(decode(natural<1>, 0b1010U) == 0b0000U);
          {
            const auto [i, j] = decode(0b1010U);
            CHECK(i == 0b0011U);
            CHECK(j == 0b0000U);
          }

          CHECK(decode(natural<0>, 0b1111U) == 0b0011U);
          CHECK(decode(natural<1>, 0b1111U) == 0b0011U);
          {
            const auto [i, j] = decode(0b1111U);
            CHECK(i == 0b0011U);
            CHECK(j == 0b0011U);
          }
        }
      }

      SECTION("4bits/index") {}
    }

    SECTION("column major") {}
  }

} // end of namespace morton::testing
