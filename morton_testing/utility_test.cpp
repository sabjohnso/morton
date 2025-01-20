//
// ... morton header files
//
#include <morton/bits/utility.hpp>

//
// ... Testing header files
//
#include <catch2/catch_test_macros.hpp>

namespace morton::utility::testing {
  TEST_CASE("utility") {
    SECTION("ilog2") {
      CHECK(0u == ilog2(1u));
      CHECK(4u == ilog2(1u << 4));
      CHECK(8u == ilog2(1u << 8));
    }
  }

} // namespace morton::utility::testing
