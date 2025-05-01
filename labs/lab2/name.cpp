#include "name.h"
#include <cctype>

void Name::normalize( ){
    n[0] = toupper(n[0]);
    for(size_t i = 1; i < n.size(); i++){
        n[i] = tolower(n[i]);
    }
}