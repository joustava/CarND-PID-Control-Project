#ifndef _OPTIMIZER_H_
#define _OPTIMIZER_H_

#include <vector>
#include "Controller.h"

class Optimizer {
  private:
    double tolerance = 0.001;
  public:
    Optimizer();
    virtual ~Optimizer();
    void run(Controller* &ctrl);
};

#endif