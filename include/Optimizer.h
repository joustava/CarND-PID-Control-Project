/**
 * @file Optimizer.h
 * @author Joost Oostdijk (joustava@gmail.com)
 * @brief  Optimizer using the Twiddle Algorithm based on https://martin-thoma.com/twiddle/
 * @version 0.1
 * @date 2021-02-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _OPTIMIZER_H_
#define _OPTIMIZER_H_

#include <vector>
#include "PID.h"

/**
 * Optimizer using the Twiddle Algorithm based on https://martin-thoma.com/twiddle/
 * 
 * */
class Optimizer {
  private:
    double tolerance = 0.05;
  public:
    Optimizer();
    virtual ~Optimizer();
    /**
     * Optimize the controller gains by applying an optimization algorithm.
     * 
     * @see PID(double Kp_, double Ki_, double Kd_);
     * @param ctrl Controller to be optimized
     */
    void run(PID &pid) const;
};

#endif