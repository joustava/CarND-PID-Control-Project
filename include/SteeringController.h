#ifndef _STEERING_CTRL_
#define _STEERING_CTRL_

#include "Controller.h"
#include "Optimizer.h"
#include "PID.h"

/**
 * @brief SteeringController takes care of steering specific gains and output range.
 * 
 * The steering controller wraps a PID controller to do the actual error response calculations.
 * It uses an optimizer to update the PID gain. 
 */
class SteeringController: public Controller {
  private:
    PID pid;
    Optimizer opt;

  public:
    SteeringController();
    virtual ~SteeringController();
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
    virtual void init(double Kp_ = 0.085, double Ki_ = 0.00065, double Kd_ = 2.2) override;
    virtual double update(double cte) override;
    virtual double error() override;
};

#endif