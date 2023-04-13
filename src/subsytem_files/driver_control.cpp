#include "ARMS/chassis.h"
#include "ARMS/selector.h"
#include "pros/misc.h"
#include "subsystem_headers/globals.hpp"
#include "subsystem_headers/cata.h"

void driver_control(){
    double left_joystick;
    double right_joystick;
    bool Intake_running = true;
    int reverse_intake = 1;
    bool load = true;
    
    arms::selector::destroy();

    while(true){
        left_joystick = Controller1.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        right_joystick = Controller1.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        arms::chassis::arcade(left_joystick, right_joystick);

    if(Controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
      Intake_running = !Intake_running;
    }
    if(Controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){
      reverse_intake *= -1;
    }
    if(Intake_running == true){
      intake_motor.move_velocity(600 * reverse_intake);
    }
    else{
      intake_motor.brake();
    }

    /*
    if(load){
        if(cata_stop.get() > 80){
            cata.move_velocity(100);
        }
        else{
            cata.brake();
            load = false;
        }
    }
    */

    if(Controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){
        SHOOT;
        /*
        cata.move_velocity(100);
        pros::delay(400);
        load = true;
        cata.brake();
        */
    }
    else if(Controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)){
        SHOOT_BOOST;
        /*
        cata.move_velocity(100);
        pros::delay(100);
        piston_boost.set_value(1);
        pros::delay(300);
        piston_boost.set_value(0);
        load = true;
        cata.brake();
        */
    }


    pros::lcd::print(0,"Left Motors Efficency");
    pros::lcd::print(1, "%f, %f, %f", arms::chassis::leftMotors->get_efficiencies()[0],arms::chassis::leftMotors->get_efficiencies()[1],arms::chassis::leftMotors->get_efficiencies()[2]);
    pros::lcd::print(3,"Right Motors Efficency");
    pros::lcd::print(4, "%f, %f, %f", arms::chassis::rightMotors->get_efficiencies()[0],arms::chassis::rightMotors->get_efficiencies()[1],arms::chassis::rightMotors->get_efficiencies()[2]);

    pros::delay(20);
    }
}