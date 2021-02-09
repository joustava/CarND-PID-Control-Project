// Implements
#include "ThrottleController.h"
// For: std::abs
#include <complex>

ThrottleController::ThrottleController(double Kp_, double Ki_, double Kd_, bool optimize) 
  : pid{Kp_, Ki_, Kd_}, is_optimized{optimize} { }

ThrottleController::~ThrottleController() { }

double ThrottleController::update(double cte) {
  if(is_optimized) opt.run(pid);
  
  pid.UpdateError(cte);
  double throttle_value = pid.TotalError();

  if (throttle_value < 0) return 0.0;
  if (throttle_value > 1.0) return 0.95;
  return throttle_value;
}