#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  p_error = 0;
  i_error = 0;
  d_error = 0;

}

// steering = -tau * crosstrack_error


void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

}

double PID::P_term(double cte) {
  p_error = -Kp * cte;
  return p_error;
}

double PID::D_term(double cte, double prev_cte) {
  d_error = -Kd * (cte - prev_cte);
  return d_error;
}


double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return p_error + i_error + d_error;  // TODO: Add your total error calc here!
}