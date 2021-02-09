#include <catch2/catch.hpp>
#include "ThrottleController.h"
#include "SteeringController.h"
#include "Optimizer.h"
#include <random>

TEST_CASE("ThrottleController smoke test", "[ThrottleController]") {
    ThrottleController ctrl;
    
    REQUIRE(ctrl.update(-0.5) >= 0);
}

TEST_CASE("PID Optimization smoke test", "[Optimizer]") {
    Optimizer optimizer;
    // PID pid{0.08, 0.0006, 2.0};
    PID pid{0.225, 0.0004, 4};
    
    std::random_device rd;  // random
    std::mt19937 gen(rd()); // seed
    std::uniform_real_distribution<> cte(-1, 1); // range
   
    // CAPTURE("seed value");
    // emulate process by running PID with random input between -1 and 1. 
    for(int i = 0; i < 1000; i++) {
        pid.UpdateError(cte(gen));
    }

    optimizer.run(pid);

    REQUIRE(pid.TotalError());
    // REQUIRE(pid.gains()[0] == 0.08);
    // REQUIRE(pid.gains()[1] == 0.0006);
    // REQUIRE(pid.gains()[2] == 2.0);
}