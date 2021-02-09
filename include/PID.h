/**
 * @file PID.h
 * @author Joost Oostdijk (joustava@gmail.com)
 * @brief PID Controller
 * @version 0.1
 * @date 2021-02-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _PID_H_
#define _PID_H_

#include <vector>

class PID {
  public:
  /** 
   * @brief PID contructor.
   * 
   * Manual optimization:
   * - 1. find a Kp which makes system behave ok. (control)
   * - 2. find a Kd which improves dealing with load disturbance (i.e cornering)
   * - 3. find a Ki for stability
   * 
   * @param Kp_ The initial P coefficient/gain
   * @param Ki_ The initial I coefficient/gain
   * @param Kd_ The initial D coefficient/gain
   */
  PID(double Kp_, double Ki_, double Kd_);
  // PID();
  virtual ~PID();

  /** 
   * @brief PID contructor.
   * 
   * Manual optimization:
   * - 1. find a Kp which makes system behave ok. (control)
   * - 2. find a Kd which improves dealing with load disturbance (i.e cornering)
   * - 3. find a Ki for stability
   * 
   * @param Kp_ The initial P coefficient/gain
   * @param Ki_ The initial I coefficient/gain
   * @param Kd_ The initial D coefficient/gain
   */
  // void Init(double Kp_, double Ki_, double Kd_);

  /**
   * @brief Update the PID error variables given cross track error.
   * 
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * @brief Proportional term of the PID controller
   * 
   * @return double 
   */
  double P_term() const;

  /**
   * @brief  Derivative term of the PID controller
   * 
   * @return double 
   */
  double D_term() const;

  /**
   * @brief  Integral term of the PID controller
   * 
   * @return double 
   */
  double I_term() const;

  /**
   * @brief Calculates the total PID error.
   * 
   * @return double The total PID error
   */
  double TotalError() const;

  /**
   * @brief returns the set gains as vector in P,I,D order.
   * 
   * @return std::vector<double> 
   */
  std::vector<double> gains() const;

  /**
   * @brief Adjust PID gains
   * 
   * @param Kp 
   * @param Ki 
   * @param Kd 
   */
  void adjust(const double Kp_, const double Ki_, const double Kd_);
  void adjust(std::vector<double> &gains);

 private:
  /**
   * @brief PID term errors
   */
  double p_error;
  double i_error;
  double d_error;
  
  /**
   * @brief previously seen cte, to be used in D term
   * 
   */
  double cte_prev;
  
  /**
   * @brief PID Coefficients/Gains
   * 
   */
  double Kp;
  double Ki;
  double Kd;
};

#endif  // PID_H