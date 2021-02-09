/**
 * @file ThrottleController.h
 * @author Joost Oostdijk (joustava@gmail.com)
 * @brief ThrottleController takes care of throttle specific gains and output range.
 * @version 0.1
 * @date 2021-02-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _THROTTLE_CTRL_
#define _THROTTLE_CTRL_

#include "Controller.h"
#include "Optimizer.h"
#include "PID.h"

/**
 * @brief ThrottleController takes care of throttle specific gains and output range.
 * 
 * The throttle controller wraps a PID Controller to do the actual error response calculations.
 * It uses an Optimizer to update the PID gains. 
 *
 */
class ThrottleController: public Controller {
  private:
    PID pid;
    Optimizer opt;
    bool is_optimized = false;
  public:
    /**
     * @brief Construct a new Throttle Controller object
     * 
     * @param Kp_ Proportional gain
     * @param Ki_ Integral gain
     * @param Kd_ Deriviative gain
     * @param optimize enable/disable process optimization, default = false.
     */
    ThrottleController(const double Kp_ = 0.01, const double Ki_ = 0.0, const double Kd_ = 0.0, bool optimize = false);
    
    /**
     * @brief Destroy the Throttle Controller object
     * 
     */
    virtual ~ThrottleController();

    /**
     * @brief Updates process error and returns resulting throttle response.
     * 
     * @param cte 
     * @return double 
     */
    virtual double update(const double cte) override;
};

#endif