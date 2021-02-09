/**
 * @file PID.h
 * @author Joost Oostdijk (joustava@gmail.com)
 * @brief PID Controller.
 * @version 0.1
 * @date 2021-02-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _PID_H_
#define _PID_H_

#include <vector>

/**
 * @brief Proportional, Integral and Derivative controller.
 */
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

  /**
   * @brief Destroy the PID object
   */
  virtual ~PID();

  /**
   * @brief Update the PID error variables based on the supplied cross track error (CTE).
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
   * @brief Calculate the total PID error.
   * 
   * @return double The total PID error
   */
  double TotalError() const;

  /**
   * @brief returns current gains as std::vector<double> in Kp, Ki and Kd order.
   * 
   * @return std::vector<double> 
   */
  std::vector<double> gains() const;

  /**
   * @brief Adjust PID gains/coefficients
   * 
   * @param std::vector<double> containing Kp, Ki and Kd in that order. 
   */
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