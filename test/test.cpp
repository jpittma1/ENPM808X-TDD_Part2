#include <gtest/gtest.h>
#include "lib1.hpp"
#include "lib2.hpp"
#include "../include/pid.hpp"

TEST(dummy_test, dummy) {
  EXPECT_EQ(1, 1);
}

// PID_controller pid_test;

// TEST(compute, this_should_pass) {
//   EXPECT_NEAR(pid_test.compute(10.0), 10, 0.2);;
// }

// TEST(compute, this_should_pass_too) {
//    ASSERT_GT(pid_test.compute(100.0), 25); 
// }
