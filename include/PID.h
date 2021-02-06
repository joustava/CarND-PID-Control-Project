#ifndef _PID_H_
#define _PID_H_

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * 
   * 1. find a Kp which makes system behave ok. (control)
   * 2. find a Kd which improves dealing with load disturbance (i.e cornering)
   * 3. find a Ki for stability
   * 
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * @brief Proportional term of the PID controller
   * 
   * @return double 
   */
  double P_term();

  /**
   * @brief  Derivative term of the PID controller
   * 
   * @return double 
   */
  double D_term();

  /**
   * @brief  Integral term of the PID controller
   * 
   * @return double 
   */
  double I_term();

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

 private:
  /**
   * PID Errors
   */
  double p_error;
  double i_error;
  double d_error;
  double cte_prev;
  
  /**
   * PID Coefficients
   */ 
  double Kp;
  double Ki;
  double Kd;
};

#endif  // PID_H