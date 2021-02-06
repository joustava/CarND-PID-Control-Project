# C++ PID Controller

> This repository contains the work for the PID Controller project in the Self-Driving Car Engineer Nanodegree Program of Udacity.

The required writeup can be read from [WRITEUP](./WRITEUP.md).

## Prerequisites

Check the [starter repo](https://github.com/udacity/CarND-PID-Control-Project) for the needed dependencies. More information is only accessible by people who are already enrolled in the
CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Running the Code

This project involves the Term 2 Simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases)

```bash
./build.sh
./run.sh
```

## Testing the code

Test support is added to the project. Test are not extensive yet.
To run them:

```bash
./build.sh
./test.sh
```

## Extra

The original websocket server in main.cpp has been slightly changed from the original by making it broadcast the PID controller response instead of only sending the values to the simulator. This makes it possible to have other processes connect and get updates. With this change a simple web application could be created that shows the PID response over time in a plotly.js based graph.

The app can be run by going into `./graph-client`, run `npm i` and then `npm start`. The app is then available at the url stated in the output. 