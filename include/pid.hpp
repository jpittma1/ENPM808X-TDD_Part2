/**
 * @file pid.hpp
 * @author Rashmi Kapu (rashmik@umd.edu), Neha Madhekar (nehanm97@umd.edu)
 * @brief To initialise PID controller class and member variables and functions
 * @version 0.1
 * @date 2023-10-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <iostream>

/**
 * @brief PID_controller class
 * 
 */
class PID_controller{
  double Kp; // proportional gain
  double Ki; // integral gain
  double Kd;  // derivative gain
  double initial_vel = 0.0;  // initial velocity
  // double expected_vel;  // expected velocity

  // Variables for calculating Error
  double deltaT = 1.0;
  double prev_error = 0.0, i_error = 0.0, d_error =0.0;
  
  public :
  /**
   * @brief Construct a new pid controller object to initialise default parameters for Kp, 
   Ki, Kd, initial velocity
   * 
   */
  PID_controller();
  
  /**
   * @brief To compute the output of PID controller with the given P,I,D values
   * 
   * @param vel : Expected final velocity
   * @return double : Generated output velocity
   */
  double compute(double vel);

};