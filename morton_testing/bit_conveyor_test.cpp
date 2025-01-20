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
  TEST_CASE("bit conveyors") {
    constexpr auto size = 8;
    constexpr auto dist = 2;
    constexpr auto move = 0b00001100;
    constexpr auto hold = 0b00000011;

    constexpr Bit_Conveyor conveyor{
        .size = natural<size>,
        .dist = shift<dist>,
        .dir = left,
        .move = mask<move>,
        .hold = mask<hold>,
    };

    STATIC_CHECK(conveyor.size == natural<size>);
    STATIC_CHECK(conveyor.dist == shift<dist>);
    STATIC_CHECK(conveyor.move == mask<move>);
    STATIC_CHECK(conveyor.hold == mask<hold>);

    constexpr auto value = 0b1111;
    constexpr auto expected = 0b110011;

    STATIC_CHECK(expected == conveyor(value));
    STATIC_CHECK(std::is_unsigned_v<decltype(conveyor(value))>);

    STATIC_CHECK(expected == conveyor(value, type<std::uint8_t>));
    STATIC_CHECK(
        (std::same_as<std::uint8_t,
                      std::remove_cvref_t<decltype(conveyor(value, type<std::uint8_t>))>>));

    constexpr auto duplicated_move = 0b0000110000001100;
    constexpr auto duplicated_hold = 0b0000001100000011;

    constexpr auto duplicated_conveyor = duplicate(conveyor);
    STATIC_CHECK(duplicated_conveyor.size == natural<2 * size>);
    STATIC_CHECK(duplicated_conveyor.dist == shift<dist>);
    STATIC_CHECK(duplicated_conveyor.move == mask<duplicated_move>);
    STATIC_CHECK(duplicated_conveyor.hold == mask<duplicated_hold>);
  }

} // end of namespace morton::testing
