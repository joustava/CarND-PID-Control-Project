#include "PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  p_error = 0;
  i_error = 0;
  d_error = 0;
  cte_prev = 0;
}

void PID::UpdateError(double cte) {
    p_error = cte;
    d_error = cte - cte_prev;
    i_error += cte;
    cte_prev = cte;
}

double PID::P_term() {
  return Kp * p_error;
}

double PID::D_term() {
  return Kd * d_error;
}

double PID::I_term() {
  return Ki * i_error;
}

double PID::TotalError() {
  return -(P_term() + D_term() + I_term());
}