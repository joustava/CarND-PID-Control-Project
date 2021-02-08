#include <catch2/catch.hpp>
#include "ThrottleController.h"
#include "SteeringController.h"
#include "Optimizer.h"

TEST_CASE("ThrottleController smoke test", "[ThrottleController]") {
    ThrottleController ctrl;
    
    REQUIRE(ctrl.update(-0.5) >= 0);
    REQUIRE(ctrl.error() >= 0);
}

TEST_CASE("PID Optimization smoke test", "[Optimizer]") {
    Optimizer optimizer;
    PID pid{0.08, 0.0006, 2.0};

    srand( (unsigned)time( NULL ) );
    for(int i = 0; i < 1000; i++) {
        pid.UpdateError((double)rand()/RAND_MAX);
    }

    optimizer.run(pid);

    REQUIRE(pid.TotalError() < 1.0);
    // REQUIRE(pid.gains()[0] == 0.08);
    // REQUIRE(pid.gains()[1] == 0.0006);
    // REQUIRE(pid.gains()[2] == 2.0);
}