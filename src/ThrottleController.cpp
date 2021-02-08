// Implements
#include "ThrottleController.h"
// For: std::abs
#include <complex>

ThrottleController::ThrottleController(double Kp_, double Ki_, double Kd_, bool optimize) 
  : pid{Kp_, Ki_, Kd_}, is_optimized{optimize} { }

ThrottleController::~ThrottleController() { }

double ThrottleController::update(double cte) {
  if(is_optimized) opt.run(this);
  
  pid.UpdateError(cte);
  double error = std::abs(pid.TotalError());
  double throttle_value = (error + 1.0) / 2;

  if (throttle_value < 0) return 0.0;
  if (throttle_value > 1.0) return 0.95;
  return throttle_value;
}

double ThrottleController::error() const {
  return pid.TotalError();
}

std::vector<double> ThrottleController::gains() const {
   return pid.gains();
}

void ThrottleController::adjust(const std::vector<double> &gains) {
  pid.adjust(gains[0], gains[1], gains[2]);
}

