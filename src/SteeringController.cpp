#include "SteeringController.h"

SteeringController::SteeringController(double Kp_, double Ki_, double Kd_, bool optimize) 
  : pid{Kp_, Ki_, Kd_}, is_optimized{optimize} { }

SteeringController::~SteeringController() { }

double SteeringController::update(double cte) {
  if(is_optimized) opt.run(this);
  pid.UpdateError(cte);
  double steer_value = pid.TotalError();
  if (steer_value < -1.0) return -1.0;
  if (steer_value > 1.0) return 1.0;
  return steer_value;
}

double SteeringController::error() const {
  return pid.TotalError();
}

std::vector<double> SteeringController::gains() const {
   return pid.gains();
}

void SteeringController::adjust(const std::vector<double> &gains) {
  pid.adjust(gains[0], gains[1], gains[2]);
}

