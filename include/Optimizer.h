#ifndef _OPTIMIZER_H_
#define _OPTIMIZER_H_

#include <vector>
#include "PID.h"

/**
 * @brief Optimizer using the Twiddle Algorithm based on https://martin-thoma.com/twiddle/
 * 
 * */
class Optimizer {
  private:
    double tolerance = 0.05;
  public:
    Optimizer();
    virtual ~Optimizer();
    /**
     * @brief optimizes the controller gains by applying an optimization algorithm.
     * 
     * @param ctrl Controller to be optimized
     */
    void run(PID &pid) const;
};

#endif