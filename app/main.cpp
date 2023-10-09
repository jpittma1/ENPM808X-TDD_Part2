/**
 * @file main.cpp
 * @author Rashmi Kapu (rashmik@umd.edu), Neha Madhekar (nehanm97@umd.edu)
 * @brief Main function to set expected velocity and call pid controller class
 * @version 0.1
 * @date 2023-10-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../include/pid.hpp"

int main() {
  double result;
  PID_controller my_pid_controller;
  my_pid_controller.set_expected_velocity(25.0);
  result = my_pid_controller.compute(25.0);
  std::cout << result << std::endl;
  return 0;
}
