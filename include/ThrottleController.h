#ifndef _THROTTLE_CTRL_
#define _THROTTLE_CTRL_

#include "Controller.h"
#include "Optimizer.h"
#include "PID.h"

/**
 * @brief ThrottleController takes care of throttle specific gains and output range.
 * 
 * The throttle controller wraps a PID controller to do the actual error response calculations.
 * It uses an optimizer to update the PID gains. 
 */
class ThrottleController: public Controller {
  private:
    PID pid;
    Optimizer opt;
    bool is_optimized = false;
  public:
    ThrottleController(const double Kp_ = 0.01, const double Ki_ = 0.0, const double Kd_ = 0.0, bool optimize = false);
    // ThrottleController(double Kp_, double Ki_, double Kd_, bool optimize);
    virtual ~ThrottleController();

    /**
     * @brief Updates process error and returns resulting steering response angle.
     * 
     * @param cte 
     * @return double 
     */
    virtual double update(const double cte) override;

    /**
     * @brief returns the current total CTE of the process.
     * 
     * @return double 
     */
    virtual double error() const override;

    /**
     * @brief returns the current process gains.
     * 
     * @return std::vector<double> 
     */
    virtual std::vector<double> gains() const override;

    /**
     * @brief updates the process gains.
     * 
     * @param gains updated gains
     */
    virtual void adjust(const std::vector<double> &gains) override;
};

#endif