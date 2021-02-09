/**
 * @file SteeringController.h
 * @author Joost Oostdijk (joustava@gmail.com)
 * @brief SteeringController takes care of steering specific gains and output range.
 * @version 0.1
 * @date 2021-02-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
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
    bool is_optimized = false;
  public:
    SteeringController(const double Kp_ = 0.085, const double Ki_ = 0.00065, const double Kd_ = 2.2, bool optimize = false);
    // SteeringController(double Kp_, double Ki_, double Kd_, bool optimize);
    virtual ~SteeringController();
    
    /**
     * @brief Updates process error and returns resulting steering response angle.
     * 
     * @param cte 
     * @return double 
     */
    virtual double update(const double cte) override;
};

#endif