#include <iostream>

#include "car.h"

void output(car mcar){
    std::cout << "Car: " << mcar.get_vin()
              << (mcar.is_engine_on() ? " running" : "not running")
              << " speed: " << mcar.get_speed() << "\n";
}

int main(){

    car my_car(170.0, "BLABLABLA");

    my_car.turn_on();
    
    output(my_car);

    my_car.press_gas_pedal(25.0);

    my_car.press_brake();
    try{
        my_car.turn_off();
    } catch(std::exception &ex){
        std::cout<<"no"<<ex.what()<<"\n";
    }
    return 0;
}