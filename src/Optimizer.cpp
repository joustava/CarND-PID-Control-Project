/**
 * @file Optimizer.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Optimizer.h"
// std::vector
#include <vector>
// ?
#include <numeric>
// std::transform
#include <algorithm>
// sdt::cout
#include <iostream>

// debu/random stuff
#include<cstdlib>
#include <time.h>
#include <stdio.h>

Optimizer::Optimizer() { 
  tolerance = 0.2;
}

Optimizer::~Optimizer() { }


void Optimizer::run(PID &pid) const {
  std::vector<char> G{'p', 'i', 'd'};
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
  while(((sum > tolerance)) && std::abs(best_err) > 0.001 && it < 30) {
  
    it++;
    for(int i = 0; i < deltas.size(); i++) {
      params[i] += deltas[i];
      pid.adjust(params);
      double err = pid.TotalError();;

      if(err < best_err) {
        printf("Improvement, increased K%c for next update.\n", G[i]);
        best_err = err;
        deltas[i] *= 1.1;
      } else {
        printf("Change direction, reset K%c and update.\n", G[i]);
        params[i] -= 2.0 * deltas[i];
        pid.adjust(params);
        best_err = pid.TotalError();;
        if(err < best_err) {
          printf("Increase K%c step for next update\n", G[i]);
          best_err = err;
          deltas[i] *= 1.05;
        } else {
          printf("Decrease K%c step for next update\n", G[i]);
          params[i] += deltas[i];
          deltas[i] *= 0.5;
        }
      }
      sum = std::accumulate(deltas.begin(), deltas.end(), 0.0);
      printf("%-15.d | %-15.8f | %-15.8f | %-15.8f | %-15.8f | %-15.8f |\n", it, best_err, pid.gains()[0], pid.gains()[1], pid.gains()[2], sum);
    }
  }  
}