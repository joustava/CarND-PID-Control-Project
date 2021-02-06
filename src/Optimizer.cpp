#include "Optimizer.h"
#include <vector>
#include <numeric>

Optimizer::Optimizer() { }

Optimizer::~Optimizer() { }

/**
 * @brief Optimize by Twiddle according to https://martin-thoma.com/twiddle/
 * 
 * @param params 
 * @param changes 
 * @return std::vector<double> 
 */
void Optimizer::run(Controller* &ctrl) {
  std::vector<double> deltas{1.0, 1.0, 1.0};

  double best_err = ctrl->error(); 
  // TODO: gain updates
  while(std::accumulate(deltas.begin(), deltas.end(), 0) > tolerance) {
    for(int i = 0; i < deltas.size(); i++) {
      // params[i] += deltas[i] // support ctrl gain updates
      double err = ctrl->error();
      
      if(err < best_err) {
        best_err = err;
        deltas[i] *= 1.1;
      } else {
        // params[i] -= 2 * deltas[i]; // support ctrl gain updates
        best_err = ctrl->error();
        if(err < best_err) {
          best_err = err;
          deltas[i] *= 1.05;
        } else {
          // params[i] += deltas[i]; // support ctrl gain updates
          deltas[i] *= 0.95;
        }
      }
    }
  }
}