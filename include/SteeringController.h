#ifndef _STEERING_CTRL_
#define _STEERING_CTRL_

#include "PID.h"

/**
 * @brief SteeringController takes care of steering specific gains and output range.
 */
class SteeringController {
  private:
    PID pid;

  public:
    SteeringController();
    ~SteeringController();
    /**
     * @brief Initialize controller with PID gains.
     *
     * 1. find a Kp which makes system behave ok. (control)
     * 2. find a Kd which improves dealing with load disturbance (i.e cornering)
     * 3. find a Ki for stability
     * 
     * @param Kp_ 
     * @param Ki_ 
     * @param Kd_ 
     */
    void init(double Kp_ = 0.085, double Ki_ = 0.00065, double Kd_ = 2.2);
    double update(double cte);
};

#endif