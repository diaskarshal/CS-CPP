#include <iostream>
#include <cstring>
#include <string>

#include "string.h"

int main(int argc, char* argv[])
{
    // string copy = s1; --> copies the struct but not the data. 
    // they have the same pointer. we need to copy the data 
    // also we need another constructor: copy constructor

    string s1 = "first string";
    string s2 = s1;

    s2.print(std::cout);
    for(size_t i = 0; i < s1.len; i++){
        s1[i] = toupper(s1[i]);
    }
    s1.print(std::cout);

    return 0;
}