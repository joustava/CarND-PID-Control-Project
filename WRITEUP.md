# PID Controller

>

## Running

See [README](./README.md) for details.

## Implemenation

The implementation for the PID controller can be found from `./src/PID.cpp` and `./include/PID.h`. It is used in `./app/main.cpp` where it is fed with data from the simulator. The data consists of Cross Track Error (```double cte```) which is the error with respect to the desired line of driving, the current speed of the vehicle (```double speed```), and the current steering angle (```double angle```). The output of the PID controller is a new steering angle (```double steer_value```) that, when the PID control is applied iteratively, will reduce the error such that the error is minimized and the desired line of driving is accomplished. The car/simulator itself decides what is the desired line of driving and we only need to minimize the error and send the new steering angle to the simulator.

The PID controller needs to be initialsed with certain gain values for each term. These will be found manually at first to get a feel of the controller performance.

### Proportional term

### Integral term

### Derivative term

## Hyperparameters

## Explanatory video

## Checklist

- [ ] Code must compile without errors with cmake and make.
- [ ] The PID procedure follows what was taught in the lessons.
- [ ] Describe the effect each of the P, I, D components had in your implementation.
- [ ] Describe how the final hyperparameters were chosen.
- [ ] The vehicle must successfully drive a lap around the track. 

## Resources

- [PID controller on Wikipedia](https://en.wikipedia.org/wiki/PID_controller)