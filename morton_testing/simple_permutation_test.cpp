//
// ... morton header files
//
#include <morton/morton.hpp>

//
// ... Testing header files
//
#include <catch2/catch_test_macros.hpp>

//
// ... Standard header files
//
#include <concepts>
#include <type_traits>

namespace morton::testing {
  TEST_CASE("bit permutations") {
    constexpr auto size = 8;
    constexpr auto dist = 2;
    constexpr auto move = 0b00001100;
    constexpr auto hold = 0b00000011;

    constexpr Simple_Permutation permutation{
        .size = natural<size>,
        .dist = shift<dist>,
        .dir = left,
        .move = mask<move>,
        .hold = mask<hold>,
    };

    STATIC_CHECK(permutation.size == natural<size>);
    STATIC_CHECK(permutation.dist == shift<dist>);
    STATIC_CHECK(permutation.move == mask<move>);
    STATIC_CHECK(permutation.hold == mask<hold>);

    constexpr auto value = 0b1111;
    constexpr auto expected = 0b110011;

    STATIC_CHECK(expected == permutation(value));
    STATIC_CHECK(std::is_unsigned_v<decltype(permutation(value))>);

    STATIC_CHECK(expected == permutation(value, type<std::uint8_t>));
    STATIC_CHECK(
        (std::same_as<std::uint8_t,
                      std::remove_cvref_t<decltype(permutation(value, type<std::uint8_t>))>>));

    constexpr auto duplicated_move = 0b0000110000001100;
    constexpr auto duplicated_hold = 0b0000001100000011;

    constexpr auto duplicated_permutation = duplicate(permutation);
    STATIC_CHECK(duplicated_permutation.size == natural<2 * size>);
    STATIC_CHECK(duplicated_permutation.dist == shift<dist>);
    STATIC_CHECK(duplicated_permutation.move == mask<duplicated_move>);
    STATIC_CHECK(duplicated_permutation.hold == mask<duplicated_hold>);
  }

} // end of namespace morton::testing
