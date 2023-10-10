/**
 * @file pid.cpp
 * @author Rashmi Kapu (rashmik@umd.edu), Neha Madhekar (nehanm97@umd.edu)
 * @author Jerry Pittman (jpittma1@umd.edu)
 * @brief To initialise the members variables of the class 'PID_Controller' and implement the member functions
 * @version 0.1
 * @date 2023-10-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../../include/pid.hpp"

/**
 * @brief Computes the output of the PID controller
 * 
 * @param vel : double
 * @return double 
 */
double PID_controller::compute(double vel) {
  double current_velocity = initial_vel;
  
  // Feedback Loop to reduce error
  int iterations = 300;
  for (int i  = 0; i < iterations; i++) {
    // Proportional Error
    double error =  vel - current_velocity;

    // Derivative Error
    d_error = (error - prev_error) /deltaT; 

    // Integral Error
    i_error += error * deltaT;
    
    // Solve for output Velocity based on PID Controller
    double output_vel = (Kp * error) + (Ki * i_error) + (Kd * d_error);
    current_velocity += output_vel;
    
    // Update Previous Error
    prev_error = error;
  }
 
  return current_velocity;
}

/**
 * @brief Construct a new pid controller::pid controller object
 * 
 */
PID_controller::PID_controller() {
  PID_controller::Kp = 0.5;
  PID_controller::Kd = 0.011;
  PID_controller::Ki = 0.01;
  PID_controller::initial_vel = 0.0;
}
