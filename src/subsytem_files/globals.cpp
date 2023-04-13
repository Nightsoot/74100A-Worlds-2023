

#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"

double x_offset;
double y_offset;
double angle_offset;
int shooting = 0;
pros::Controller Controller1(pros::E_CONTROLLER_MASTER);
pros::Controller Controller2(pros::E_CONTROLLER_PARTNER);
pros::Motor intake_motor(10);
pros::Motor cata(21);
pros::Distance cata_stop(19);
pros::ADIDigitalOut piston_boost(7);