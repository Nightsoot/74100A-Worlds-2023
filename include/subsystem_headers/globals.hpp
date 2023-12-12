#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "pros/distance.hpp"
#include "pros/adi.hpp"

extern double x_offset;
extern double y_offset;
extern double angle_offset;
extern int shooting;
extern pros::Controller Controller1;
extern pros::Controller Controller2;
extern pros::Motor intake_motor;
extern pros::Motor cata;
extern pros::Distance cata_stop;
extern pros::ADIDigitalOut piston_boost;


void shoot_loop();