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
     * @brief Initialize SteeringController with PID gains.
     *
     * 1. find a Kp which makes system behave ok. (control)
     * 2. find a Kd which improves dealing with load disturbance (i.e cornering)
     * 3. find a Ki for stability
     * 
     * The default values are sufficient to get the simulation go around the track several times.
     * 
     * @param Kp_ 
     * @param Ki_ 
     * @param Kd_ 
     */
    // virtual void init(const double Kp_ = 0.085, const double Ki_ = 0.00065, const double Kd_ = 2.2, bool optimize = false) override;
    
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