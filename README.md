# PID Controller README

> This repository contains the work for the PID Controller project in the Self-Driving Car Engineer Nanodegree Program of Udacity.

The required writeup can be read from [WRITEUP](./WRITEUP.md).

## Prerequisites

Check the [starter repo](https://github.com/udacity/CarND-PID-Control-Project) for the needed dependencies. More information is only accessible by people who are already enrolled in the
CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Project structure

The project aims to follow a [Modern CMake](https://cliutils.gitlab.io/modern-cmake/) setup. It has several targets, an app target containing the complete application (`./app`), a PID library (`./src` and `./include`) and the tests (`./test`). Each part has its own `CMakeList.txt` file which are glued together in the main `CMakeList.txt` found in the root of the project.

```bash
├── CMakeLists.txt              # 'main' project CMakeLists.txt.
├── Doxyfile                    # Doxygen configuration to generate documentation
├── app                         # Agent application to steer simulation
│   ├── CMakeLists.txt          
│   └── main.cpp
├── docs
├── graph-client                # Web application showing steering and throttle values 
├── include                     # Library headers
│   ├── Controller.h
│   ├── Optimizer.h
│   ├── PID.h
│   ├── SteeringController.h
│   └── ThrottleController.h
├── reports                      # Reports generated by CppCheck 
├── src                          # PID Library implementation
│   ├── CMakeLists.txt
│   ├── Optimizer.cpp
│   ├── PID.cpp
│   ├── SteeringController.cpp
│   └── ThrottleController.cpp
├── test                         # unit/smoke tests
│   ├── CMakeLists.txt
│   ├── PID_test.cpp
│   └── support.cpp
.
.
.
└── writeup-assets                # Assets for writeup
```

## Running the Code

This project involves the Term 2 Simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases)
Then with the running simulator this PID controller can be build and run with

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
### Websocket changes in main.cpp

The original websocket server in `./app/main.cpp` has been slightly changed from the original by making it broadcast the PID controller response instead of only sending the values to the simulator. This makes it possible to have other processes connect and get updates. With this change a simple web application could be created that shows the PID response over time in a [plotly.js](https://plotly.com/javascript/) based graph.

The app can be run by going into `./graph-client`, run `npm i` and then `npm start`. The app is then available at the url stated in the output, by default `localhost:1234`.

### CppCheck

With [CppCheck](http://cppcheck.sourceforge.net/manual.pdf) one can improve code quality by checking common errors.

Installation and dependencies

```bash
brew install cppcheck
pip install pygments # only once if complaining about missing pygments...
```

Now reports can be generated by running the `report.sh` script

```bash
./report.sh
```

### Doxygen

With [Doxygen]() and [Graphviz]() installed, documentation can be written in Doxygen/Javadoc style and an html version generated.

```bash
brew install doxygen
brew install graphviz
```

Running the supplied `./docs.sh` script will generate html documentations that can be viewed (opened by script) in the browser.

```bash
./docs.sh
```

## TODO

### Twiddle

TBD...
### Valgrind

Some optimizations to the code could be made with the help of [Valgrind](https://www.valgrind.org/) by following the [Valgrind quickstart](https://www.valgrind.org/docs/manual/quick-start.html). What the process boils down to is to compile the project with debugging enabled and lowest level of optimization: ```./build -d o0```.
Install Valgrind (on a Mac):

```bash
brew tap LouisBrunner/valgrind
brew install --HEAD https://raw.githubusercontent.com/sowson/valgrind/master/valgrind.rb
```

and then run Valgrind to get optimization hints/warnings:

```bash
valgrind --leak-check=yes ./bin/pid
```

## Resources

- [Interesting read about C++ tooling](https://invisible-island.net/personal/lint-tools.html#background)
- [Debug Macros](https://stackoverflow.com/questions/14251038/debug-macros-in-c)
- [Modern CMake](https://cliutils.gitlab.io/modern-cmake/)