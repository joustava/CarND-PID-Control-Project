#include "SteeringController.h"

SteeringController::SteeringController(double Kp_, double Ki_, double Kd_, bool optimize) 
  : pid{Kp_, Ki_, Kd_}, is_optimized{optimize} { }

SteeringController::~SteeringController() { }

double SteeringController::update(double cte) {
  if(is_optimized) opt.run(pid);
  pid.UpdateError(cte);
  double steer_value = pid.TotalError();
  if (steer_value < -1.0) return -1.0;
  if (steer_value > 1.0) return 1.0;
  return steer_value;
}