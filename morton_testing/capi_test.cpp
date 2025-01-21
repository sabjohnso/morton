//
// ... matmul header files
//
#include <morton/capi.h>

//
// ... Testing header files
//
#include <catch2/catch_test_macros.hpp>

namespace morton::testing {
  TEST_CASE("C-API") {

    SECTION("64bit") {
      SECTION("2-dimensional") {
        SECTION("32bits/index") {
          CHECK(morton64bit_encode2d_32bits_per_index(0, 0) == 0);
          CHECK(morton64bit_encode2d_32bits_per_index(0, 1) == 1);
          CHECK(morton64bit_encode2d_32bits_per_index(1, 0) == 2);
          CHECK(morton64bit_encode2d_32bits_per_index(1, 1) == 3);

          CHECK(morton64bit_decode2d_32bits_per_index_0(0) == 0);
          CHECK(morton64bit_decode2d_32bits_per_index_1(0) == 0);
          {
            const auto [i, j] = morton64bit_decode2d_32bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
          }

          CHECK(morton64bit_decode2d_32bits_per_index_0(1) == 0);
          CHECK(morton64bit_decode2d_32bits_per_index_1(1) == 1);
          {
            const auto [i, j] = morton64bit_decode2d_32bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 1);
          }

          CHECK(morton64bit_decode2d_32bits_per_index_0(2) == 1);
          CHECK(morton64bit_decode2d_32bits_per_index_1(2) == 0);
          {
            const auto [i, j] = morton64bit_decode2d_32bits_per_index(2).indices;
            CHECK(i == 1);
            CHECK(j == 0);
          }

          CHECK(morton64bit_decode2d_32bits_per_index_0(3) == 1);
          CHECK(morton64bit_decode2d_32bits_per_index_1(3) == 1);
          {
            const auto [i, j] = morton64bit_decode2d_32bits_per_index(3).indices;
            CHECK(i == 1);
            CHECK(j == 1);
          }
        }

        SECTION("16bits/index") {
          CHECK(morton64bit_encode2d_16bits_per_index(0, 0) == 0);
          CHECK(morton64bit_encode2d_16bits_per_index(0, 1) == 1);
          CHECK(morton64bit_encode2d_16bits_per_index(1, 0) == 2);
          CHECK(morton64bit_encode2d_16bits_per_index(1, 1) == 3);

          CHECK(morton64bit_decode2d_16bits_per_index_0(0) == 0);
          CHECK(morton64bit_decode2d_16bits_per_index_1(0) == 0);
          {
            const auto [i, j] = morton64bit_decode2d_16bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
          }

          CHECK(morton64bit_decode2d_16bits_per_index_0(1) == 0);
          CHECK(morton64bit_decode2d_16bits_per_index_1(1) == 1);
          {
            const auto [i, j] = morton64bit_decode2d_16bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 1);
          }

          CHECK(morton64bit_decode2d_16bits_per_index_0(2) == 1);
          CHECK(morton64bit_decode2d_16bits_per_index_1(2) == 0);
          {
            const auto [i, j] = morton64bit_decode2d_16bits_per_index(2).indices;
            CHECK(i == 1);
            CHECK(j == 0);
          }

          CHECK(morton64bit_decode2d_16bits_per_index_0(3) == 1);
          CHECK(morton64bit_decode2d_16bits_per_index_1(3) == 1);
          {
            const auto [i, j] = morton64bit_decode2d_16bits_per_index(3).indices;
            CHECK(i == 1);
            CHECK(j == 1);
          }
        }

        SECTION("8bits/index") {
          CHECK(morton64bit_encode2d_8bits_per_index(0, 0) == 0);
          CHECK(morton64bit_encode2d_8bits_per_index(0, 1) == 1);
          CHECK(morton64bit_encode2d_8bits_per_index(1, 0) == 2);
          CHECK(morton64bit_encode2d_8bits_per_index(1, 1) == 3);

          CHECK(morton64bit_decode2d_8bits_per_index_0(0) == 0);
          CHECK(morton64bit_decode2d_8bits_per_index_1(0) == 0);
          {
            const auto [i, j] = morton64bit_decode2d_8bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
          }

          CHECK(morton64bit_decode2d_8bits_per_index_0(1) == 0);
          CHECK(morton64bit_decode2d_8bits_per_index_1(1) == 1);
          {
            const auto [i, j] = morton64bit_decode2d_8bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 1);
          }

          CHECK(morton64bit_decode2d_8bits_per_index_0(2) == 1);
          CHECK(morton64bit_decode2d_8bits_per_index_1(2) == 0);
          {
            const auto [i, j] = morton64bit_decode2d_8bits_per_index(2).indices;
            CHECK(i == 1);
            CHECK(j == 0);
          }

          CHECK(morton64bit_decode2d_8bits_per_index_0(3) == 1);
          CHECK(morton64bit_decode2d_8bits_per_index_1(3) == 1);
          {
            const auto [i, j] = morton64bit_decode2d_8bits_per_index(3).indices;
            CHECK(i == 1);
            CHECK(j == 1);
          }
        }

        SECTION("4bits/index") {
          CHECK(morton64bit_encode2d_4bits_per_index(0, 0) == 0);
          CHECK(morton64bit_encode2d_4bits_per_index(0, 1) == 1);
          CHECK(morton64bit_encode2d_4bits_per_index(1, 0) == 2);
          CHECK(morton64bit_encode2d_4bits_per_index(1, 1) == 3);

          CHECK(morton64bit_decode2d_4bits_per_index_0(0) == 0);
          CHECK(morton64bit_decode2d_4bits_per_index_1(0) == 0);
          {
            const auto [i, j] = morton64bit_decode2d_4bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
          }

          CHECK(morton64bit_decode2d_4bits_per_index_0(1) == 0);
          CHECK(morton64bit_decode2d_4bits_per_index_1(1) == 1);
          {
            const auto [i, j] = morton64bit_decode2d_4bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 1);
          }

          CHECK(morton64bit_decode2d_4bits_per_index_0(2) == 1);
          CHECK(morton64bit_decode2d_4bits_per_index_1(2) == 0);
          {
            const auto [i, j] = morton64bit_decode2d_4bits_per_index(2).indices;
            CHECK(i == 1);
            CHECK(j == 0);
          }

          CHECK(morton64bit_decode2d_4bits_per_index_0(3) == 1);
          CHECK(morton64bit_decode2d_4bits_per_index_1(3) == 1);
          {
            const auto [i, j] = morton64bit_decode2d_4bits_per_index(3).indices;
            CHECK(i == 1);
            CHECK(j == 1);
          }
        }

        SECTION("2bits/index") {
          CHECK(morton64bit_encode2d_2bits_per_index(0, 0) == 0);
          CHECK(morton64bit_encode2d_2bits_per_index(0, 1) == 1);
          CHECK(morton64bit_encode2d_2bits_per_index(1, 0) == 2);
          CHECK(morton64bit_encode2d_2bits_per_index(1, 1) == 3);

          CHECK(morton64bit_decode2d_2bits_per_index_0(0) == 0);
          CHECK(morton64bit_decode2d_2bits_per_index_1(0) == 0);
          {
            const auto [i, j] = morton64bit_decode2d_2bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
          }

          CHECK(morton64bit_decode2d_2bits_per_index_0(1) == 0);
          CHECK(morton64bit_decode2d_2bits_per_index_1(1) == 1);
          {
            const auto [i, j] = morton64bit_decode2d_2bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 1);
          }

          CHECK(morton64bit_decode2d_2bits_per_index_0(2) == 1);
          CHECK(morton64bit_decode2d_2bits_per_index_1(2) == 0);
          {
            const auto [i, j] = morton64bit_decode2d_2bits_per_index(2).indices;
            CHECK(i == 1);
            CHECK(j == 0);
          }

          CHECK(morton64bit_decode2d_2bits_per_index_0(3) == 1);
          CHECK(morton64bit_decode2d_2bits_per_index_1(3) == 1);
          {
            const auto [i, j] = morton64bit_decode2d_2bits_per_index(3).indices;
            CHECK(i == 1);
            CHECK(j == 1);
          }
        }
      }

      SECTION("3-dimensional") {
        SECTION("22bits/index") {
          CHECK(morton64bit_encode3d_22bits_per_index(0, 0, 0) == 0);
          CHECK(morton64bit_encode3d_22bits_per_index(0, 0, 1) == 1);
          CHECK(morton64bit_encode3d_22bits_per_index(0, 1, 0) == 2);
          CHECK(morton64bit_encode3d_22bits_per_index(0, 1, 1) == 3);
          CHECK(morton64bit_encode3d_22bits_per_index(1, 0, 0) == 4);
          CHECK(morton64bit_encode3d_22bits_per_index(1, 0, 1) == 5);
          CHECK(morton64bit_encode3d_22bits_per_index(1, 1, 0) == 6);
          CHECK(morton64bit_encode3d_22bits_per_index(1, 1, 1) == 7);

          CHECK(morton64bit_decode3d_22bits_per_index_0(0) == 0);
          CHECK(morton64bit_decode3d_22bits_per_index_1(0) == 0);
          CHECK(morton64bit_decode3d_22bits_per_index_2(0) == 0);
          {
            const auto [i, j, k] = morton64bit_decode3d_22bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 0);
          }

          CHECK(morton64bit_decode3d_22bits_per_index_0(1) == 0);
          CHECK(morton64bit_decode3d_22bits_per_index_1(1) == 0);
          CHECK(morton64bit_decode3d_22bits_per_index_2(1) == 1);
          {
            const auto [i, j, k] = morton64bit_decode3d_22bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 1);
          }

          CHECK(morton64bit_decode3d_22bits_per_index_0(2) == 0);
          CHECK(morton64bit_decode3d_22bits_per_index_1(2) == 1);
          CHECK(morton64bit_decode3d_22bits_per_index_2(2) == 0);
          {
            const auto [i, j, k] = morton64bit_decode3d_22bits_per_index(2).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 0);
          }

          CHECK(morton64bit_decode3d_22bits_per_index_0(3) == 0);
          CHECK(morton64bit_decode3d_22bits_per_index_1(3) == 1);
          CHECK(morton64bit_decode3d_22bits_per_index_2(3) == 1);
          {
            const auto [i, j, k] = morton64bit_decode3d_22bits_per_index(3).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 1);
          }
        }

        SECTION("16bits/index") {
          CHECK(morton64bit_encode3d_16bits_per_index(0, 0, 0) == 0);
          CHECK(morton64bit_encode3d_16bits_per_index(0, 0, 1) == 1);
          CHECK(morton64bit_encode3d_16bits_per_index(0, 1, 0) == 2);
          CHECK(morton64bit_encode3d_16bits_per_index(0, 1, 1) == 3);
          CHECK(morton64bit_encode3d_16bits_per_index(1, 0, 0) == 4);
          CHECK(morton64bit_encode3d_16bits_per_index(1, 0, 1) == 5);
          CHECK(morton64bit_encode3d_16bits_per_index(1, 1, 0) == 6);
          CHECK(morton64bit_encode3d_16bits_per_index(1, 1, 1) == 7);

          CHECK(morton64bit_decode3d_16bits_per_index_0(0) == 0);
          CHECK(morton64bit_decode3d_16bits_per_index_1(0) == 0);
          CHECK(morton64bit_decode3d_16bits_per_index_2(0) == 0);
          {
            const auto [i, j, k] = morton64bit_decode3d_16bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 0);
          }

          CHECK(morton64bit_decode3d_16bits_per_index_0(1) == 0);
          CHECK(morton64bit_decode3d_16bits_per_index_1(1) == 0);
          CHECK(morton64bit_decode3d_16bits_per_index_2(1) == 1);
          {
            const auto [i, j, k] = morton64bit_decode3d_16bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 1);
          }

          CHECK(morton64bit_decode3d_16bits_per_index_0(2) == 0);
          CHECK(morton64bit_decode3d_16bits_per_index_1(2) == 1);
          CHECK(morton64bit_decode3d_16bits_per_index_2(2) == 0);
          {
            const auto [i, j, k] = morton64bit_decode3d_16bits_per_index(2).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 0);
          }

          CHECK(morton64bit_decode3d_16bits_per_index_0(3) == 0);
          CHECK(morton64bit_decode3d_16bits_per_index_1(3) == 1);
          CHECK(morton64bit_decode3d_16bits_per_index_2(3) == 1);
          {
            const auto [i, j, k] = morton64bit_decode3d_16bits_per_index(3).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 1);
          }
        }

        SECTION("8bits/index") {
          CHECK(morton64bit_encode3d_8bits_per_index(0, 0, 0) == 0);
          CHECK(morton64bit_encode3d_8bits_per_index(0, 0, 1) == 1);
          CHECK(morton64bit_encode3d_8bits_per_index(0, 1, 0) == 2);
          CHECK(morton64bit_encode3d_8bits_per_index(0, 1, 1) == 3);
          CHECK(morton64bit_encode3d_8bits_per_index(1, 0, 0) == 4);
          CHECK(morton64bit_encode3d_8bits_per_index(1, 0, 1) == 5);
          CHECK(morton64bit_encode3d_8bits_per_index(1, 1, 0) == 6);
          CHECK(morton64bit_encode3d_8bits_per_index(1, 1, 1) == 7);

          CHECK(morton64bit_decode3d_8bits_per_index_0(0) == 0);
          CHECK(morton64bit_decode3d_8bits_per_index_1(0) == 0);
          CHECK(morton64bit_decode3d_8bits_per_index_2(0) == 0);
          {
            const auto [i, j, k] = morton64bit_decode3d_8bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 0);
          }

          CHECK(morton64bit_decode3d_8bits_per_index_0(1) == 0);
          CHECK(morton64bit_decode3d_8bits_per_index_1(1) == 0);
          CHECK(morton64bit_decode3d_8bits_per_index_2(1) == 1);
          {
            const auto [i, j, k] = morton64bit_decode3d_8bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 1);
          }

          CHECK(morton64bit_decode3d_8bits_per_index_0(2) == 0);
          CHECK(morton64bit_decode3d_8bits_per_index_1(2) == 1);
          CHECK(morton64bit_decode3d_8bits_per_index_2(2) == 0);
          {
            const auto [i, j, k] = morton64bit_decode3d_8bits_per_index(2).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 0);
          }

          CHECK(morton64bit_decode3d_8bits_per_index_0(3) == 0);
          CHECK(morton64bit_decode3d_8bits_per_index_1(3) == 1);
          CHECK(morton64bit_decode3d_8bits_per_index_2(3) == 1);
          {
            const auto [i, j, k] = morton64bit_decode3d_8bits_per_index(3).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 1);
          }
        }

        SECTION("4bits/index") {
          CHECK(morton64bit_encode3d_4bits_per_index(0, 0, 0) == 0);
          CHECK(morton64bit_encode3d_4bits_per_index(0, 0, 1) == 1);
          CHECK(morton64bit_encode3d_4bits_per_index(0, 1, 0) == 2);
          CHECK(morton64bit_encode3d_4bits_per_index(0, 1, 1) == 3);
          CHECK(morton64bit_encode3d_4bits_per_index(1, 0, 0) == 4);
          CHECK(morton64bit_encode3d_4bits_per_index(1, 0, 1) == 5);
          CHECK(morton64bit_encode3d_4bits_per_index(1, 1, 0) == 6);
          CHECK(morton64bit_encode3d_4bits_per_index(1, 1, 1) == 7);

          CHECK(morton64bit_decode3d_4bits_per_index_0(0) == 0);
          CHECK(morton64bit_decode3d_4bits_per_index_1(0) == 0);
          CHECK(morton64bit_decode3d_4bits_per_index_2(0) == 0);
          {
            const auto [i, j, k] = morton64bit_decode3d_4bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 0);
          }

          CHECK(morton64bit_decode3d_4bits_per_index_0(1) == 0);
          CHECK(morton64bit_decode3d_4bits_per_index_1(1) == 0);
          CHECK(morton64bit_decode3d_4bits_per_index_2(1) == 1);
          {
            const auto [i, j, k] = morton64bit_decode3d_4bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 1);
          }

          CHECK(morton64bit_decode3d_4bits_per_index_0(2) == 0);
          CHECK(morton64bit_decode3d_4bits_per_index_1(2) == 1);
          CHECK(morton64bit_decode3d_4bits_per_index_2(2) == 0);
          {
            const auto [i, j, k] = morton64bit_decode3d_4bits_per_index(2).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 0);
          }

          CHECK(morton64bit_decode3d_4bits_per_index_0(3) == 0);
          CHECK(morton64bit_decode3d_4bits_per_index_1(3) == 1);
          CHECK(morton64bit_decode3d_4bits_per_index_2(3) == 1);
          {
            const auto [i, j, k] = morton64bit_decode3d_4bits_per_index(3).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 1);
          }
        }

        SECTION("2bits/index") {
          CHECK(morton64bit_encode3d_2bits_per_index(0, 0, 0) == 0);
          CHECK(morton64bit_encode3d_2bits_per_index(0, 0, 1) == 1);
          CHECK(morton64bit_encode3d_2bits_per_index(0, 1, 0) == 2);
          CHECK(morton64bit_encode3d_2bits_per_index(0, 1, 1) == 3);
          CHECK(morton64bit_encode3d_2bits_per_index(1, 0, 0) == 4);
          CHECK(morton64bit_encode3d_2bits_per_index(1, 0, 1) == 5);
          CHECK(morton64bit_encode3d_2bits_per_index(1, 1, 0) == 6);
          CHECK(morton64bit_encode3d_2bits_per_index(1, 1, 1) == 7);

          CHECK(morton64bit_decode3d_2bits_per_index_0(0) == 0);
          CHECK(morton64bit_decode3d_2bits_per_index_1(0) == 0);
          CHECK(morton64bit_decode3d_2bits_per_index_2(0) == 0);
          {
            const auto [i, j, k] = morton64bit_decode3d_2bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 0);
          }

          CHECK(morton64bit_decode3d_2bits_per_index_0(1) == 0);
          CHECK(morton64bit_decode3d_2bits_per_index_1(1) == 0);
          CHECK(morton64bit_decode3d_2bits_per_index_2(1) == 1);
          {
            const auto [i, j, k] = morton64bit_decode3d_2bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 1);
          }

          CHECK(morton64bit_decode3d_2bits_per_index_0(2) == 0);
          CHECK(morton64bit_decode3d_2bits_per_index_1(2) == 1);
          CHECK(morton64bit_decode3d_2bits_per_index_2(2) == 0);
          {
            const auto [i, j, k] = morton64bit_decode3d_2bits_per_index(2).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 0);
          }

          CHECK(morton64bit_decode3d_2bits_per_index_0(3) == 0);
          CHECK(morton64bit_decode3d_2bits_per_index_1(3) == 1);
          CHECK(morton64bit_decode3d_2bits_per_index_2(3) == 1);
          {
            const auto [i, j, k] = morton64bit_decode3d_2bits_per_index(3).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 1);
          }
        }
      }
    }

    SECTION("32bit") {
      SECTION("2-dimensional") {
        SECTION("8bits/index") {
          CHECK(morton32bit_encode2d_8bits_per_index(0, 0) == 0);
          CHECK(morton32bit_encode2d_8bits_per_index(0, 1) == 1);
          CHECK(morton32bit_encode2d_8bits_per_index(1, 0) == 2);
          CHECK(morton32bit_encode2d_8bits_per_index(1, 1) == 3);

          CHECK(morton32bit_decode2d_8bits_per_index_0(0) == 0);
          CHECK(morton32bit_decode2d_8bits_per_index_1(0) == 0);
          {
            const auto [i, j] = morton32bit_decode2d_8bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
          }

          CHECK(morton32bit_decode2d_8bits_per_index_0(1) == 0);
          CHECK(morton32bit_decode2d_8bits_per_index_1(1) == 1);
          {
            const auto [i, j] = morton32bit_decode2d_8bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 1);
          }

          CHECK(morton32bit_decode2d_8bits_per_index_0(2) == 1);
          CHECK(morton32bit_decode2d_8bits_per_index_1(2) == 0);
          {
            const auto [i, j] = morton32bit_decode2d_8bits_per_index(2).indices;
            CHECK(i == 1);
            CHECK(j == 0);
          }

          CHECK(morton32bit_decode2d_8bits_per_index_0(3) == 1);
          CHECK(morton32bit_decode2d_8bits_per_index_1(3) == 1);
          {
            const auto [i, j] = morton32bit_decode2d_8bits_per_index(3).indices;
            CHECK(i == 1);
            CHECK(j == 1);
          }
        }

        SECTION("4bits/index") {
          CHECK(morton32bit_encode2d_4bits_per_index(0, 0) == 0);
          CHECK(morton32bit_encode2d_4bits_per_index(0, 1) == 1);
          CHECK(morton32bit_encode2d_4bits_per_index(1, 0) == 2);
          CHECK(morton32bit_encode2d_4bits_per_index(1, 1) == 3);

          CHECK(morton32bit_decode2d_4bits_per_index_0(0) == 0);
          CHECK(morton32bit_decode2d_4bits_per_index_1(0) == 0);
          {
            const auto [i, j] = morton32bit_decode2d_4bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
          }

          CHECK(morton32bit_decode2d_4bits_per_index_0(1) == 0);
          CHECK(morton32bit_decode2d_4bits_per_index_1(1) == 1);
          {
            const auto [i, j] = morton32bit_decode2d_4bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 1);
          }

          CHECK(morton32bit_decode2d_4bits_per_index_0(2) == 1);
          CHECK(morton32bit_decode2d_4bits_per_index_1(2) == 0);
          {
            const auto [i, j] = morton32bit_decode2d_4bits_per_index(2).indices;
            CHECK(i == 1);
            CHECK(j == 0);
          }

          CHECK(morton32bit_decode2d_4bits_per_index_0(3) == 1);
          CHECK(morton32bit_decode2d_4bits_per_index_1(3) == 1);
          {
            const auto [i, j] = morton32bit_decode2d_4bits_per_index(3).indices;
            CHECK(i == 1);
            CHECK(j == 1);
          }
        }

        SECTION("2bits/index") {
          CHECK(morton32bit_encode2d_2bits_per_index(0, 0) == 0);
          CHECK(morton32bit_encode2d_2bits_per_index(0, 1) == 1);
          CHECK(morton32bit_encode2d_2bits_per_index(1, 0) == 2);
          CHECK(morton32bit_encode2d_2bits_per_index(1, 1) == 3);

          CHECK(morton32bit_decode2d_2bits_per_index_0(0) == 0);
          CHECK(morton32bit_decode2d_2bits_per_index_1(0) == 0);
          {
            const auto [i, j] = morton32bit_decode2d_2bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
          }

          CHECK(morton32bit_decode2d_2bits_per_index_0(1) == 0);
          CHECK(morton32bit_decode2d_2bits_per_index_1(1) == 1);
          {
            const auto [i, j] = morton32bit_decode2d_2bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 1);
          }

          CHECK(morton32bit_decode2d_2bits_per_index_0(2) == 1);
          CHECK(morton32bit_decode2d_2bits_per_index_1(2) == 0);
          {
            const auto [i, j] = morton32bit_decode2d_2bits_per_index(2).indices;
            CHECK(i == 1);
            CHECK(j == 0);
          }

          CHECK(morton32bit_decode2d_2bits_per_index_0(3) == 1);
          CHECK(morton32bit_decode2d_2bits_per_index_1(3) == 1);
          {
            const auto [i, j] = morton32bit_decode2d_2bits_per_index(3).indices;
            CHECK(i == 1);
            CHECK(j == 1);
          }
        }
      }

      SECTION("3-dimensional") {

        SECTION("4bits/index") {
          CHECK(morton32bit_encode3d_4bits_per_index(0, 0, 0) == 0);
          CHECK(morton32bit_encode3d_4bits_per_index(0, 0, 1) == 1);
          CHECK(morton32bit_encode3d_4bits_per_index(0, 1, 0) == 2);
          CHECK(morton32bit_encode3d_4bits_per_index(0, 1, 1) == 3);
          CHECK(morton32bit_encode3d_4bits_per_index(1, 0, 0) == 4);
          CHECK(morton32bit_encode3d_4bits_per_index(1, 0, 1) == 5);
          CHECK(morton32bit_encode3d_4bits_per_index(1, 1, 0) == 6);
          CHECK(morton32bit_encode3d_4bits_per_index(1, 1, 1) == 7);

          CHECK(morton32bit_decode3d_4bits_per_index_0(0) == 0);
          CHECK(morton32bit_decode3d_4bits_per_index_1(0) == 0);
          CHECK(morton32bit_decode3d_4bits_per_index_2(0) == 0);
          {
            const auto [i, j, k] = morton32bit_decode3d_4bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 0);
          }

          CHECK(morton32bit_decode3d_4bits_per_index_0(1) == 0);
          CHECK(morton32bit_decode3d_4bits_per_index_1(1) == 0);
          CHECK(morton32bit_decode3d_4bits_per_index_2(1) == 1);
          {
            const auto [i, j, k] = morton32bit_decode3d_4bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 1);
          }

          CHECK(morton32bit_decode3d_4bits_per_index_0(2) == 0);
          CHECK(morton32bit_decode3d_4bits_per_index_1(2) == 1);
          CHECK(morton32bit_decode3d_4bits_per_index_2(2) == 0);
          {
            const auto [i, j, k] = morton32bit_decode3d_4bits_per_index(2).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 0);
          }

          CHECK(morton32bit_decode3d_4bits_per_index_0(3) == 0);
          CHECK(morton32bit_decode3d_4bits_per_index_1(3) == 1);
          CHECK(morton32bit_decode3d_4bits_per_index_2(3) == 1);
          {
            const auto [i, j, k] = morton32bit_decode3d_4bits_per_index(3).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 1);
          }
        }

        SECTION("2bits/index") {
          CHECK(morton32bit_encode3d_2bits_per_index(0, 0, 0) == 0);
          CHECK(morton32bit_encode3d_2bits_per_index(0, 0, 1) == 1);
          CHECK(morton32bit_encode3d_2bits_per_index(0, 1, 0) == 2);
          CHECK(morton32bit_encode3d_2bits_per_index(0, 1, 1) == 3);
          CHECK(morton32bit_encode3d_2bits_per_index(1, 0, 0) == 4);
          CHECK(morton32bit_encode3d_2bits_per_index(1, 0, 1) == 5);
          CHECK(morton32bit_encode3d_2bits_per_index(1, 1, 0) == 6);
          CHECK(morton32bit_encode3d_2bits_per_index(1, 1, 1) == 7);

          CHECK(morton32bit_decode3d_2bits_per_index_0(0) == 0);
          CHECK(morton32bit_decode3d_2bits_per_index_1(0) == 0);
          CHECK(morton32bit_decode3d_2bits_per_index_2(0) == 0);
          {
            const auto [i, j, k] = morton32bit_decode3d_2bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 0);
          }

          CHECK(morton32bit_decode3d_2bits_per_index_0(1) == 0);
          CHECK(morton32bit_decode3d_2bits_per_index_1(1) == 0);
          CHECK(morton32bit_decode3d_2bits_per_index_2(1) == 1);
          {
            const auto [i, j, k] = morton32bit_decode3d_2bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 1);
          }

          CHECK(morton32bit_decode3d_2bits_per_index_0(2) == 0);
          CHECK(morton32bit_decode3d_2bits_per_index_1(2) == 1);
          CHECK(morton32bit_decode3d_2bits_per_index_2(2) == 0);
          {
            const auto [i, j, k] = morton32bit_decode3d_2bits_per_index(2).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 0);
          }

          CHECK(morton32bit_decode3d_2bits_per_index_0(3) == 0);
          CHECK(morton32bit_decode3d_2bits_per_index_1(3) == 1);
          CHECK(morton32bit_decode3d_2bits_per_index_2(3) == 1);
          {
            const auto [i, j, k] = morton32bit_decode3d_2bits_per_index(3).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 1);
          }
        }
      }
    }

    SECTION("16bit") {
      SECTION("2-dimensional") {
        SECTION("8bits/index") {
          CHECK(morton16bit_encode2d_8bits_per_index(0, 0) == 0);
          CHECK(morton16bit_encode2d_8bits_per_index(0, 1) == 1);
          CHECK(morton16bit_encode2d_8bits_per_index(1, 0) == 2);
          CHECK(morton16bit_encode2d_8bits_per_index(1, 1) == 3);

          CHECK(morton16bit_decode2d_8bits_per_index_0(0) == 0);
          CHECK(morton16bit_decode2d_8bits_per_index_1(0) == 0);
          {
            const auto [i, j] = morton16bit_decode2d_8bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
          }

          CHECK(morton16bit_decode2d_8bits_per_index_0(1) == 0);
          CHECK(morton16bit_decode2d_8bits_per_index_1(1) == 1);
          {
            const auto [i, j] = morton16bit_decode2d_8bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 1);
          }

          CHECK(morton16bit_decode2d_8bits_per_index_0(2) == 1);
          CHECK(morton16bit_decode2d_8bits_per_index_1(2) == 0);
          {
            const auto [i, j] = morton16bit_decode2d_8bits_per_index(2).indices;
            CHECK(i == 1);
            CHECK(j == 0);
          }

          CHECK(morton16bit_decode2d_8bits_per_index_0(3) == 1);
          CHECK(morton16bit_decode2d_8bits_per_index_1(3) == 1);
          {
            const auto [i, j] = morton16bit_decode2d_8bits_per_index(3).indices;
            CHECK(i == 1);
            CHECK(j == 1);
          }
        }

        SECTION("4bits/index") {
          CHECK(morton16bit_encode2d_4bits_per_index(0, 0) == 0);
          CHECK(morton16bit_encode2d_4bits_per_index(0, 1) == 1);
          CHECK(morton16bit_encode2d_4bits_per_index(1, 0) == 2);
          CHECK(morton16bit_encode2d_4bits_per_index(1, 1) == 3);

          CHECK(morton16bit_decode2d_4bits_per_index_0(0) == 0);
          CHECK(morton16bit_decode2d_4bits_per_index_1(0) == 0);
          {
            const auto [i, j] = morton16bit_decode2d_4bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
          }

          CHECK(morton16bit_decode2d_4bits_per_index_0(1) == 0);
          CHECK(morton16bit_decode2d_4bits_per_index_1(1) == 1);
          {
            const auto [i, j] = morton16bit_decode2d_4bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 1);
          }

          CHECK(morton16bit_decode2d_4bits_per_index_0(2) == 1);
          CHECK(morton16bit_decode2d_4bits_per_index_1(2) == 0);
          {
            const auto [i, j] = morton16bit_decode2d_4bits_per_index(2).indices;
            CHECK(i == 1);
            CHECK(j == 0);
          }

          CHECK(morton16bit_decode2d_4bits_per_index_0(3) == 1);
          CHECK(morton16bit_decode2d_4bits_per_index_1(3) == 1);
          {
            const auto [i, j] = morton16bit_decode2d_4bits_per_index(3).indices;
            CHECK(i == 1);
            CHECK(j == 1);
          }
        }

        SECTION("2bits/index") {
          CHECK(morton16bit_encode2d_2bits_per_index(0, 0) == 0);
          CHECK(morton16bit_encode2d_2bits_per_index(0, 1) == 1);
          CHECK(morton16bit_encode2d_2bits_per_index(1, 0) == 2);
          CHECK(morton16bit_encode2d_2bits_per_index(1, 1) == 3);

          CHECK(morton16bit_decode2d_2bits_per_index_0(0) == 0);
          CHECK(morton16bit_decode2d_2bits_per_index_1(0) == 0);
          {
            const auto [i, j] = morton16bit_decode2d_2bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
          }

          CHECK(morton16bit_decode2d_2bits_per_index_0(1) == 0);
          CHECK(morton16bit_decode2d_2bits_per_index_1(1) == 1);
          {
            const auto [i, j] = morton16bit_decode2d_2bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 1);
          }

          CHECK(morton16bit_decode2d_2bits_per_index_0(2) == 1);
          CHECK(morton16bit_decode2d_2bits_per_index_1(2) == 0);
          {
            const auto [i, j] = morton16bit_decode2d_2bits_per_index(2).indices;
            CHECK(i == 1);
            CHECK(j == 0);
          }

          CHECK(morton16bit_decode2d_2bits_per_index_0(3) == 1);
          CHECK(morton16bit_decode2d_2bits_per_index_1(3) == 1);
          {
            const auto [i, j] = morton16bit_decode2d_2bits_per_index(3).indices;
            CHECK(i == 1);
            CHECK(j == 1);
          }
        }
      }

      SECTION("3-dimensional") {

        SECTION("5bits/index") {
          CHECK(morton16bit_encode3d_5bits_per_index(0, 0, 0) == 0);
          CHECK(morton16bit_encode3d_5bits_per_index(0, 0, 1) == 1);
          CHECK(morton16bit_encode3d_5bits_per_index(0, 1, 0) == 2);
          CHECK(morton16bit_encode3d_5bits_per_index(0, 1, 1) == 3);
          CHECK(morton16bit_encode3d_5bits_per_index(1, 0, 0) == 4);
          CHECK(morton16bit_encode3d_5bits_per_index(1, 0, 1) == 5);
          CHECK(morton16bit_encode3d_5bits_per_index(1, 1, 0) == 6);
          CHECK(morton16bit_encode3d_5bits_per_index(1, 1, 1) == 7);

          CHECK(morton16bit_decode3d_5bits_per_index_0(0) == 0);
          CHECK(morton16bit_decode3d_5bits_per_index_1(0) == 0);
          CHECK(morton16bit_decode3d_5bits_per_index_2(0) == 0);
          {
            const auto [i, j, k] = morton16bit_decode3d_5bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 0);
          }

          CHECK(morton16bit_decode3d_5bits_per_index_0(1) == 0);
          CHECK(morton16bit_decode3d_5bits_per_index_1(1) == 0);
          CHECK(morton16bit_decode3d_5bits_per_index_2(1) == 1);
          {
            const auto [i, j, k] = morton16bit_decode3d_5bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 1);
          }

          CHECK(morton16bit_decode3d_5bits_per_index_0(2) == 0);
          CHECK(morton16bit_decode3d_5bits_per_index_1(2) == 1);
          CHECK(morton16bit_decode3d_5bits_per_index_2(2) == 0);
          {
            const auto [i, j, k] = morton16bit_decode3d_5bits_per_index(2).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 0);
          }

          CHECK(morton16bit_decode3d_5bits_per_index_0(3) == 0);
          CHECK(morton16bit_decode3d_5bits_per_index_1(3) == 1);
          CHECK(morton16bit_decode3d_5bits_per_index_2(3) == 1);
          {
            const auto [i, j, k] = morton16bit_decode3d_5bits_per_index(3).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 1);
          }
        }

        SECTION("4bits/index") {
          CHECK(morton16bit_encode3d_4bits_per_index(0, 0, 0) == 0);
          CHECK(morton16bit_encode3d_4bits_per_index(0, 0, 1) == 1);
          CHECK(morton16bit_encode3d_4bits_per_index(0, 1, 0) == 2);
          CHECK(morton16bit_encode3d_4bits_per_index(0, 1, 1) == 3);
          CHECK(morton16bit_encode3d_4bits_per_index(1, 0, 0) == 4);
          CHECK(morton16bit_encode3d_4bits_per_index(1, 0, 1) == 5);
          CHECK(morton16bit_encode3d_4bits_per_index(1, 1, 0) == 6);
          CHECK(morton16bit_encode3d_4bits_per_index(1, 1, 1) == 7);

          CHECK(morton16bit_decode3d_4bits_per_index_0(0) == 0);
          CHECK(morton16bit_decode3d_4bits_per_index_1(0) == 0);
          CHECK(morton16bit_decode3d_4bits_per_index_2(0) == 0);
          {
            const auto [i, j, k] = morton16bit_decode3d_4bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 0);
          }

          CHECK(morton16bit_decode3d_4bits_per_index_0(1) == 0);
          CHECK(morton16bit_decode3d_4bits_per_index_1(1) == 0);
          CHECK(morton16bit_decode3d_4bits_per_index_2(1) == 1);
          {
            const auto [i, j, k] = morton16bit_decode3d_4bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 1);
          }

          CHECK(morton16bit_decode3d_4bits_per_index_0(2) == 0);
          CHECK(morton16bit_decode3d_4bits_per_index_1(2) == 1);
          CHECK(morton16bit_decode3d_4bits_per_index_2(2) == 0);
          {
            const auto [i, j, k] = morton16bit_decode3d_4bits_per_index(2).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 0);
          }

          CHECK(morton16bit_decode3d_4bits_per_index_0(3) == 0);
          CHECK(morton16bit_decode3d_4bits_per_index_1(3) == 1);
          CHECK(morton16bit_decode3d_4bits_per_index_2(3) == 1);
          {
            const auto [i, j, k] = morton16bit_decode3d_4bits_per_index(3).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 1);
          }
        }

        SECTION("2bits/index") {
          CHECK(morton16bit_encode3d_2bits_per_index(0, 0, 0) == 0);
          CHECK(morton16bit_encode3d_2bits_per_index(0, 0, 1) == 1);
          CHECK(morton16bit_encode3d_2bits_per_index(0, 1, 0) == 2);
          CHECK(morton16bit_encode3d_2bits_per_index(0, 1, 1) == 3);
          CHECK(morton16bit_encode3d_2bits_per_index(1, 0, 0) == 4);
          CHECK(morton16bit_encode3d_2bits_per_index(1, 0, 1) == 5);
          CHECK(morton16bit_encode3d_2bits_per_index(1, 1, 0) == 6);
          CHECK(morton16bit_encode3d_2bits_per_index(1, 1, 1) == 7);

          CHECK(morton16bit_decode3d_2bits_per_index_0(0) == 0);
          CHECK(morton16bit_decode3d_2bits_per_index_1(0) == 0);
          CHECK(morton16bit_decode3d_2bits_per_index_2(0) == 0);
          {
            const auto [i, j, k] = morton16bit_decode3d_2bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 0);
          }

          CHECK(morton16bit_decode3d_2bits_per_index_0(1) == 0);
          CHECK(morton16bit_decode3d_2bits_per_index_1(1) == 0);
          CHECK(morton16bit_decode3d_2bits_per_index_2(1) == 1);
          {
            const auto [i, j, k] = morton16bit_decode3d_2bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 1);
          }

          CHECK(morton16bit_decode3d_2bits_per_index_0(2) == 0);
          CHECK(morton16bit_decode3d_2bits_per_index_1(2) == 1);
          CHECK(morton16bit_decode3d_2bits_per_index_2(2) == 0);
          {
            const auto [i, j, k] = morton16bit_decode3d_2bits_per_index(2).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 0);
          }

          CHECK(morton16bit_decode3d_2bits_per_index_0(3) == 0);
          CHECK(morton16bit_decode3d_2bits_per_index_1(3) == 1);
          CHECK(morton16bit_decode3d_2bits_per_index_2(3) == 1);
          {
            const auto [i, j, k] = morton16bit_decode3d_2bits_per_index(3).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 1);
          }
        }
      }
    }

    SECTION("8bit") {
      SECTION("2-dimensional") {
        SECTION("4bits/index") {
          CHECK(morton8bit_encode2d_4bits_per_index(0, 0) == 0);
          CHECK(morton8bit_encode2d_4bits_per_index(0, 1) == 1);
          CHECK(morton8bit_encode2d_4bits_per_index(1, 0) == 2);
          CHECK(morton8bit_encode2d_4bits_per_index(1, 1) == 3);

          CHECK(morton8bit_decode2d_4bits_per_index_0(0) == 0);
          CHECK(morton8bit_decode2d_4bits_per_index_1(0) == 0);
          {
            const auto [i, j] = morton8bit_decode2d_4bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
          }

          CHECK(morton8bit_decode2d_4bits_per_index_0(1) == 0);
          CHECK(morton8bit_decode2d_4bits_per_index_1(1) == 1);
          {
            const auto [i, j] = morton8bit_decode2d_4bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 1);
          }

          CHECK(morton8bit_decode2d_4bits_per_index_0(2) == 1);
          CHECK(morton8bit_decode2d_4bits_per_index_1(2) == 0);
          {
            const auto [i, j] = morton8bit_decode2d_4bits_per_index(2).indices;
            CHECK(i == 1);
            CHECK(j == 0);
          }

          CHECK(morton8bit_decode2d_4bits_per_index_0(3) == 1);
          CHECK(morton8bit_decode2d_4bits_per_index_1(3) == 1);
          {
            const auto [i, j] = morton8bit_decode2d_4bits_per_index(3).indices;
            CHECK(i == 1);
            CHECK(j == 1);
          }
        }

        SECTION("2bits/index") {
          CHECK(morton8bit_encode2d_2bits_per_index(0, 0) == 0);
          CHECK(morton8bit_encode2d_2bits_per_index(0, 1) == 1);
          CHECK(morton8bit_encode2d_2bits_per_index(1, 0) == 2);
          CHECK(morton8bit_encode2d_2bits_per_index(1, 1) == 3);

          CHECK(morton8bit_decode2d_2bits_per_index_0(0) == 0);
          CHECK(morton8bit_decode2d_2bits_per_index_1(0) == 0);
          {
            const auto [i, j] = morton8bit_decode2d_2bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
          }

          CHECK(morton8bit_decode2d_2bits_per_index_0(1) == 0);
          CHECK(morton8bit_decode2d_2bits_per_index_1(1) == 1);
          {
            const auto [i, j] = morton8bit_decode2d_2bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 1);
          }

          CHECK(morton8bit_decode2d_2bits_per_index_0(2) == 1);
          CHECK(morton8bit_decode2d_2bits_per_index_1(2) == 0);
          {
            const auto [i, j] = morton8bit_decode2d_2bits_per_index(2).indices;
            CHECK(i == 1);
            CHECK(j == 0);
          }

          CHECK(morton8bit_decode2d_2bits_per_index_0(3) == 1);
          CHECK(morton8bit_decode2d_2bits_per_index_1(3) == 1);
          {
            const auto [i, j] = morton8bit_decode2d_2bits_per_index(3).indices;
            CHECK(i == 1);
            CHECK(j == 1);
          }
        }
      }

      SECTION("3-dimensional") {
        SECTION("2bits/index") {
          CHECK(morton8bit_encode3d_2bits_per_index(0, 0, 0) == 0);
          CHECK(morton8bit_encode3d_2bits_per_index(0, 0, 1) == 1);
          CHECK(morton8bit_encode3d_2bits_per_index(0, 1, 0) == 2);
          CHECK(morton8bit_encode3d_2bits_per_index(0, 1, 1) == 3);
          CHECK(morton8bit_encode3d_2bits_per_index(1, 0, 0) == 4);
          CHECK(morton8bit_encode3d_2bits_per_index(1, 0, 1) == 5);
          CHECK(morton8bit_encode3d_2bits_per_index(1, 1, 0) == 6);
          CHECK(morton8bit_encode3d_2bits_per_index(1, 1, 1) == 7);

          CHECK(morton8bit_decode3d_2bits_per_index_0(0) == 0);
          CHECK(morton8bit_decode3d_2bits_per_index_1(0) == 0);
          CHECK(morton8bit_decode3d_2bits_per_index_2(0) == 0);
          {
            const auto [i, j, k] = morton8bit_decode3d_2bits_per_index(0).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 0);
          }

          CHECK(morton8bit_decode3d_2bits_per_index_0(1) == 0);
          CHECK(morton8bit_decode3d_2bits_per_index_1(1) == 0);
          CHECK(morton8bit_decode3d_2bits_per_index_2(1) == 1);
          {
            const auto [i, j, k] = morton8bit_decode3d_2bits_per_index(1).indices;
            CHECK(i == 0);
            CHECK(j == 0);
            CHECK(k == 1);
          }

          CHECK(morton8bit_decode3d_2bits_per_index_0(2) == 0);
          CHECK(morton8bit_decode3d_2bits_per_index_1(2) == 1);
          CHECK(morton8bit_decode3d_2bits_per_index_2(2) == 0);
          {
            const auto [i, j, k] = morton8bit_decode3d_2bits_per_index(2).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 0);
          }

          CHECK(morton8bit_decode3d_2bits_per_index_0(3) == 0);
          CHECK(morton8bit_decode3d_2bits_per_index_1(3) == 1);
          CHECK(morton8bit_decode3d_2bits_per_index_2(3) == 1);
          {
            const auto [i, j, k] = morton8bit_decode3d_2bits_per_index(3).indices;
            CHECK(i == 0);
            CHECK(j == 1);
            CHECK(k == 1);
          }
        }
      }
    }
  }
} // end of namespace morton::testing
