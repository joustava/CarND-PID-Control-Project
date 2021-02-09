/**
 * @file Controller.h
 * @author Joost Oostdijk (joustava@gmail.com)
 * @brief Controller base class that encapsulates the PID processing steps.
 * @version 0.1
 * @date 2021-02-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <vector>

/**
 * @brief Controller base class that encapsulates the PID processing steps.
 */
class Controller {
  public:
    Controller() = default;
    virtual ~Controller() = default;
    
    /**
     * @brief Set the initial process gains
     * 
     * @param Kp_ 
     * @param Ki_ 
     * @param Kd_ 
     */
    // virtual void init(const double Kp_, const double Ki_, const double Kd_, bool optimize = false) = 0;
    
    /**
     * @brief update error calculations
     * 
     * @param cte 
     * @return double 
     */
    virtual double update(const double cte) = 0;
    
    /**
     * @brief Helper for optimization, returns the current process error
     * 
     * @return double 
     */
    virtual double error() const = 0;
    
    /**
     * @brief Helper for optimization, returns the current process gains.
     * 
     * @return std::vector<double> 
     */
    virtual std::vector<double> gains() const = 0;

    /**
     * @brief Helper for optimization, updates the process gains.
     * 
     * @param gains updated gains
     */
    virtual void adjust(const std::vector<double> &gains) = 0;
};

#endif