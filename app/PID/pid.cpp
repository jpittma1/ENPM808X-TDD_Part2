#include "../../include/pid.hpp"

double PID_controller::compute(double vel) {
    //add implementation here
    return 0.0;
};

PID_controller::PID_controller(){
  PID_controller::Kp = 0.5;
  PID_controller::Kd = 0.011;
  PID_controller::Ki = 0.01;
  PID_controller::initial_vel = 0.0;
};

void PID_controller::set_expected_velocity(double expected_result){
  PID_controller::expected_vel = expected_result;
};