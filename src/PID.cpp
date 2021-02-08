#include "PID.h"

PID::PID(const double Kp_, const double Ki_, const double Kd_) : 
  p_error{0}, i_error{0}, d_error{0}, cte_prev{0},
  Kp{Kp_}, Ki{Ki_}, Kd{Kd_} { }

PID::~PID() {}

void PID::UpdateError(double cte) {
    p_error = cte;
    d_error = cte - cte_prev;
    i_error += cte;
    cte_prev = cte;
}

double PID::P_term() const {
  return Kp * p_error;
}

double PID::D_term() const {
  return Kd * d_error;
}

double PID::I_term() const {
  return Ki * i_error;
}

double PID::TotalError() const {
  return -(P_term() + D_term() + I_term());
}

std::vector<double> PID::gains() const {
  std::vector<double> g{Kp, Ki, Kd};
  return g;
}

void PID::adjust(const double Kp_, const double Ki_, const double Kd_) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
}

void PID::adjust(std::vector<double> &gains) {
  Kp = gains[0];
  Ki = gains[1];
  Kd = gains[2];
}