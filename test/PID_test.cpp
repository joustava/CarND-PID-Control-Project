#include <catch2/catch.hpp>
#include "ThrottleController.h"

TEST_CASE("ThrottleController response", "[ThrottleController]") {
    ThrottleController ctrl;
    
    REQUIRE(ctrl.update(-0.5) >= 0);
    REQUIRE(ctrl.error() >= 0);
}