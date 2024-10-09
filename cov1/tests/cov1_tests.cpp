#include <cov1/cov1_a.h>
#include <cov1/cov1_b.h>

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

TEST_CASE("integer square root")
{
    SECTION("sqrt(0)=0") { REQUIRE(cov1::sqrtInt(0) == 0); }

    SECTION("sqrt(4)=2") { REQUIRE(cov1::sqrtInt(4) == 2); }

    SECTION("sqrt(100)=10") { REQUIRE(cov1::sqrtInt(100) == 10); }

    SECTION("sqrt(-1) throws an error") { REQUIRE_THROWS(cov1::sqrtInt(-1)); }
}

TEST_CASE("integer absolute value")
{
    SECTION("abs(-5)=5") { REQUIRE(cov1::absInt(-5) == 5); }
}

TEST_CASE("integer string concatenation")
{
    SECTION("concatenating 1 and 3 results in 13")
    {
        REQUIRE(cov1::concatStr(1, 3) == "13");
    }
}
