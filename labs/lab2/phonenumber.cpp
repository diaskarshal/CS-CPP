
#include "phonenumber.h"

bool PhoneNumber::iswellformed( ) const{
    size_t counter = 0;

    for(size_t i = 1; i < nr.size(); i++){
        if(48 <= nr[i] && nr[i] <= 57)
            counter++;
        else
            return false;
    }
    
    return 10 <= counter && counter <= 20 && nr[0] == '+';
}