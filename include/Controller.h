#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <vector>

class Controller {
  public:
    Controller() = default;
    virtual ~Controller() = default;
    virtual void init(double Kp_, double Ki_, double Kd_) = 0;
    virtual double update(double cte) = 0;
    virtual double error() = 0;
};

#endif