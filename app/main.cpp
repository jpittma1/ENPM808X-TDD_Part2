#include "lib.hpp"
#include "../include/pid.hpp"
// #include "/pid/pid.cpp"
#include "lib1.hpp"
#include "lib2.hpp"

int main() {
  // dummy();
  // my_function1(30);
  // my_function2(30.3);
  double result;
  PID_controller my_pid_controller;
  my_pid_controller.set_expected_velocity(25.0);
  result = my_pid_controller.compute(25.0);
  std::cout<<result<<std::endl;
  return 0;
}
