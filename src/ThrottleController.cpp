#include "ThrottleController.h"

ThrottleController::ThrottleController(double Kp_, double Ki_, double Kd_, bool optimize) 
  : pid{Kp_, Ki_, Kd_}, is_optimized{optimize} { }

ThrottleController::~ThrottleController() { }

double ThrottleController::update(double cte) {
  if(is_optimized) opt.run(this);
  pid.UpdateError(cte);
  double throttle_value = pid.TotalError();
  if (throttle_value < -1.0) return -1.0;
  if (throttle_value > 1.0) return 1.0;
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

