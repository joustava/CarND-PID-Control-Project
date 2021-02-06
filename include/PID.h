#ifndef PID_H
#define PID_H

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


  void Init(double Kp_ = 0.085, double Ki_ = 0.00065, double Kd_ = 2.2);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);


  double P_term(double cte);

  double D_term(double cte, double cte_prev);

  double I_term(double cte);

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
  double cte_total;
  
  /**
   * PID Coefficients
   */ 
  double Kp;
  double Ki;
  double Kd;
};

#endif  // PID_H