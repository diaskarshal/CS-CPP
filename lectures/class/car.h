#include <string>

class car { //these are private
    bool engine_on;
    double speed;

    const double max_speed;
    const std::string vin;

//constructor for the car class:
 
public:

    car(double max_spd, std::string veh_id_num):
        engine_on(false),
        speed(0.0),
        max_speed(max_spd),
        vin(veh_id_num)
    {

    }

    double get_speed() const {
        return speed;
    }

    double is_engine_on() const {
        return engine_on;
    }

    double get_max_speed() const {
        return max_speed;
    }

    std::string get_vin() const{
        return vin;
    }

    bool turn_on(){
        if(engine_on) return false;

        engine_on = true;
        return true;
    }

    bool turn_off(){
        if(!engine_on) return false;
        
        if(speed > 0)
            throw std::invalid_argument("nono");

        engine_on = false;
        return true;
    }

    void press_gas_pedal(double pressure){
        if(pressure < 0.0) throw std::invalid_argument("nono");
        if(engine_on){
            unsigned int new_speed = speed + pressure;
            if(new_speed > max_speed) speed = max_speed;
            else speed = new_speed;
        }
    }

    void press_brake(){
        speed = 0;
    }

    ~car(){
        
    }
};