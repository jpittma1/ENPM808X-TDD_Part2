#pragma once

#include <iostream>

class PID_controller{
  double Kp;
  double Ki;
  double Kd;
  double initial_vel ;
  double expected_vel ;

  
  public :
  PID_controller();
  double compute(double vel);
  void set_expected_velocity(double expected_result);

};