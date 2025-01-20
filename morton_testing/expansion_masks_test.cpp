//
// ... morton header files
//
#include <morton/morton.hpp>

//
// ... Testing header files
//
#include <catch2/catch_test_macros.hpp>

namespace morton::testing {

  TEST_CASE("expansion masks") {

    SECTION("1bit/index") {
      // !! Here, note that 1 bit cannot be expanded and the expansion masks
      // just act as the identity function, reguardless of the number of indices
      // that would encoded.

      constexpr auto m = 1u;
      SECTION("2-dimensional") {
        constexpr auto ndims = 2u;
        constexpr auto masks = make_expansion_masks(bits_per_index<m>, num_indices<ndims>);

        STATIC_CHECK(conservative(masks));

        CHECK(masks(0u) == 0u);
        CHECK(masks(1u) == 1u);

        STATIC_CHECK(masks(0u) == 0u);
        STATIC_CHECK(masks(1u) == 1u);
      }

      SECTION("3-dimensional") {
        constexpr auto ndims = 3u;
        constexpr auto masks = make_expansion_masks(bits_per_index<m>, num_indices<ndims>);

        STATIC_CHECK(conservative(masks));

        CHECK(masks(0u) == 0u);
        CHECK(masks(1u) == 1u);

        STATIC_CHECK(masks(0u) == 0u);
        STATIC_CHECK(masks(1u) == 1u);
      }
    }

    SECTION("2bits/index") {
      constexpr auto m = 2u; // number of bits per index to be encoded

      SECTION("1-dimensional") {
        // !! Here, note that 1-dimensional expansion masks don't expand anything, because
        // the 1-dimensional morton ordering is just the normal ordering of natural numbes.
        // This is shown here, because the masks with one bit per index already exhibit this
        // behavior, regardless of the number of dimensions.
        //
        // I general, it is absurd to operate on 1-dimensional indices, but the functionality
        // is provided here, because there may be use cases where the dimensionality is
        // parameterized and using this encoding simplifies the general solution.

        constexpr auto ndims = 1u;
        constexpr auto masks = make_expansion_masks(bits_per_index<m>, num_indices<ndims>);

        STATIC_CHECK(conservative(masks));

        CHECK(masks(0b00u) == 0b00u);
        CHECK(masks(0b01u) == 0b01u);
        CHECK(masks(0b10u) == 0b10u);
        CHECK(masks(0b11u) == 0b11u);

        STATIC_CHECK(masks(0b00u) == 0b00u);
        STATIC_CHECK(masks(0b01u) == 0b01u);
        STATIC_CHECK(masks(0b10u) == 0b10u);
        STATIC_CHECK(masks(0b11u) == 0b11u);
      }

      SECTION("2-dimensional") {
        constexpr auto ndims = 2u;
        constexpr auto masks = make_expansion_masks(bits_per_index<m>, num_indices<ndims>);

        STATIC_CHECK(conservative(masks));

        CHECK(masks(0b0000u) == 0b0000u);
        CHECK(masks(0b0001u) == 0b0001u);
        CHECK(masks(0b0010u) == 0b0100u);
        CHECK(masks(0b0011u) == 0b0101u);

        STATIC_CHECK(masks(0b0000u) == 0b0000u);
        STATIC_CHECK(masks(0b0001u) == 0b0001u);
        STATIC_CHECK(masks(0b0010u) == 0b0100u);
        STATIC_CHECK(masks(0b0011u) == 0b0101u);
      }

      SECTION("3-dimensional") {
        constexpr auto ndims = 3u;
        constexpr auto masks = make_expansion_masks(bits_per_index<m>, num_indices<ndims>);

        STATIC_CHECK(conservative(masks));

        CHECK(masks(0b0000u) == 0b0000u);
        CHECK(masks(0b0001u) == 0b0001u);
        CHECK(masks(0b0010u) == 0b1000u);
        CHECK(masks(0b0011u) == 0b1001u);

        STATIC_CHECK(masks(0b0000u) == 0b0000u);
        STATIC_CHECK(masks(0b0001u) == 0b0001u);
        STATIC_CHECK(masks(0b0010u) == 0b1000u);
        STATIC_CHECK(masks(0b0011u) == 0b1001u);
      }
    }

    SECTION("4bits/index") {
      constexpr auto m = 4u;
      SECTION("2-dimensional") {
        constexpr auto ndims = 2u;
        constexpr auto masks = make_expansion_masks(bits_per_index<m>, num_indices<ndims>);

        STATIC_CHECK(conservative(masks));

        CHECK(masks(0b00000000u) == 0b00000000u);
        CHECK(masks(0b00000001u) == 0b00000001u);
        CHECK(masks(0b00000010u) == 0b00000100u);
        CHECK(masks(0b00000011u) == 0b00000101u);
        CHECK(masks(0b00001111u) == 0b01010101u);

        STATIC_CHECK(masks(0b00000000u) == 0b00000000u);
        STATIC_CHECK(masks(0b00000001u) == 0b00000001u);
        STATIC_CHECK(masks(0b00000010u) == 0b00000100u);
        STATIC_CHECK(masks(0b00000011u) == 0b00000101u);
        STATIC_CHECK(masks(0b00001111u) == 0b01010101u);
      }

      SECTION("3-dimensional") {
        constexpr auto ndims = 3u;
        constexpr auto masks = make_expansion_masks(bits_per_index<m>, num_indices<ndims>);

        STATIC_CHECK(conservative(masks));

        CHECK(masks(0b000000000000u) == 0b000000000000u);
        CHECK(masks(0b000000000001u) == 0b000000000001u);
        CHECK(masks(0b000000000010u) == 0b000000001000u);
        CHECK(masks(0b000000000011u) == 0b000000001001u);
        CHECK(masks(0b000000001111u) == 0b001001001001u);

        STATIC_CHECK(masks(0b000000000000u) == 0b000000000000u);
        STATIC_CHECK(masks(0b000000000001u) == 0b000000000001u);
        STATIC_CHECK(masks(0b000000000010u) == 0b000000001000u);
        STATIC_CHECK(masks(0b000000000011u) == 0b000000001001u);
        STATIC_CHECK(masks(0b000000001111u) == 0b001001001001u);
      }
    }

    SECTION("8bits/index") {}

    SECTION("16bits/index") {}

    SECTION("32bits/index") {}
  }

} // end of namespace morton::testing
