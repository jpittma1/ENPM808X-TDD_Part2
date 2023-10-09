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
  double expected_vel;  // expected velocity

  // Variables for calculating Error
  double deltaT = 0.01;
  double prev_error = 0.0;
  
  public :
  /**
   * @brief Construct a new pid controller object to initialise default parameters for Kp, 
   Ki, Kd, initial velocity
   * 
   */
  PID_controller();

  /**
   * @brief Feedback loop to iterate for PID controller
   * 
   * @param setpoint : desired velocity
   * @param current : current velocity
   * @return double : new velocity
   */
  double calculate_error(double setpoint, double current);
  
  /**
   * @brief To compute the output of PID controller with the given P,I,D values
   * 
   * @param vel : Expected final velocity
   * @return double : Generated output velocity
   */
  double compute(double vel);

  /**
   * @brief Set the expected velocity 
   * 
   * @param expected_result 
   */
  void set_expected_velocity(double expected_result);

};