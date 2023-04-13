#include "subsystem_headers/globals.hpp"

void shoot_loop(){
    bool finished_loading = false;
    while(true){
        switch(shooting){
            //normal shot
            case 1:
                cata.move_velocity(100);
                pros::delay(400);
                cata.brake();
                shooting = 3;
            //shot with boost
            case 2:
                cata.move_velocity(100);
                pros::delay(100);
                piston_boost.set_value(1);
                pros::delay(300);
                piston_boost.set_value(0);
                cata.brake();
                shooting = 3;
            //load
            case 3:
                if(cata_stop.get() > 80){
                  cata.move_velocity(100);
                }
                else{
                    cata.brake();
                    shooting = 4;
                }
            //hold position
            case 4:
                break;
        }
        pros::delay(25);
    }
}

#define SHOOT shooting = 1
#define SHOOT_BOOST shooting = 2
#define LOAD shooting = 3
