#include "Optimizer.h"
#include <vector>
#include <numeric>

Optimizer::Optimizer() { }

Optimizer::~Optimizer() { }


void Optimizer::run(Controller* ctrl) const {
  std::vector<double> deltas;
  std::transform(ctrl->gains().begin(), ctrl->gains().end(), deltas.begin(), [](const double &gain){ return gain/10.0; });   
  std::vector<double> params{ctrl->gains()};

  double best_err = ctrl->error(); 

  while(std::accumulate(deltas.begin(), deltas.end(), 0) > tolerance) {
    for(int i = 0; i < deltas.size(); i++) {
      params[i] += deltas[i];
      ctrl->adjust(params);
      double err = ctrl->error();
      
      if(err < best_err) {
        best_err = err;
        deltas[i] *= 1.1;
      } else {
        params[i] -= 2 * deltas[i];
        ctrl->adjust(params);
        best_err = ctrl->error();
        if(err < best_err) {
          best_err = err;
          deltas[i] *= 1.05;
        } else {
          params[i] += deltas[i];
          deltas[i] *= 0.95;
        }
      }
    }
  }

  
}