#include "SteeringController.h"

SteeringController::SteeringController() {};

SteeringController::~SteeringController() {};

void SteeringController::init(double Kp, double Ki, double Kd) {
  pid.Init(Kp, Ki, Kd);
}

double SteeringController::update(double cte) {
  pid.UpdateError(cte);
  double steer_value = pid.TotalError();
  if (steer_value < -1.0) return -1.0;
  if (steer_value > 1.0) return 1.0;
  return steer_value;
}
