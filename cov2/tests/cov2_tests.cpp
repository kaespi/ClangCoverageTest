#include <cov2/cov2.h>

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

TEST_CASE("linear absolute function evaluation")
{
    SECTION("function is zero when all are zero")
    {
        REQUIRE(cov2::linearEval(0, 0, 0, 0) == 0);
    }
}
