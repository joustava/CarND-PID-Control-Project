#include "Optimizer.h"
// std::vector
#include <vector>
// ?
#include <numeric>
// std::transform
#include <algorithm>
// sdt::cout
#include <iostream>

// random stuff
#include<cstdlib>
#include <time.h>
#include <stdio.h>

Optimizer::Optimizer() { 
  tolerance = 0.2;
}

Optimizer::~Optimizer() { }


void Optimizer::run(PID &pid) const {
  std::vector<double> deltas{1.0, 1.0, 1.0};
  std::vector<double> params = pid.gains();
  std::transform(params.begin(), params.end(), deltas.begin(), [](const double &gain){ return gain/10.0; });   

  double best_err = pid.TotalError();
  double sum = std::accumulate(deltas.begin(), deltas.end(), 0.0);
  // return;
  int it = 0;
  printf("%-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "iteration", "best error", "Kp", "Ki", "Kd", "delta sum");
  printf("Initial state\n");
  printf("%-15.d | %-15.8f | %-15.8f | %-15.8f | %-15.8f | %-15.8f |\n", 0, best_err, pid.gains()[0], pid.gains()[1], pid.gains()[2], sum);
  while(((sum > tolerance)) && std::abs(best_err) > 0.1 && it < 30) {
  
    it++;
    for(int i = 0; i < deltas.size(); i++) {
      params[i] += deltas[i];
      pid.adjust(params);
      double err = pid.TotalError();;

      if(err < best_err) {
        printf("Improvement detected in positive direction\n");
        best_err = err;
        deltas[i] *= 1.1;
      } else {
        printf("No improvement detected in positive direction\n");
        params[i] -= 2.0 * deltas[i];
        pid.adjust(params);
        best_err = pid.TotalError();;
        if(err < best_err) {
          printf("Improvement detected in other\n");
          best_err = err;
          deltas[i] *= 1.1;
        } else {
          printf("Decrease step size\n");
          params[i] += deltas[i];
          deltas[i] *= 0.9;
        }
      }
      sum = std::accumulate(deltas.begin(), deltas.end(), 0.0);
      printf("%-15.d | %-15.8f | %-15.8f | %-15.8f | %-15.8f | %-15.8f |\n", it, best_err, pid.gains()[0], pid.gains()[1], pid.gains()[2], sum);
    }
  }  
}