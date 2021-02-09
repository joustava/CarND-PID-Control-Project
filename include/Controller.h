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
    /**
     * @brief Construct a new Controller object.
     * 
     */
    Controller() = default;

    /**
     * @brief Destroy the Controller object.
     * 
     */
    virtual ~Controller() = default;

    /**
     * @brief update error calculations
     * 
     * @param cte 
     * @return double 
     */
    virtual double update(const double cte) = 0;
};

#endif