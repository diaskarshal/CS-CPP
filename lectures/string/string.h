#include <algorithm>
#include <iostream>

struct string{
    char * str;
    size_t cap;
    size_t len;

    string(const char * c){
        len = 0;
        while(c[len])
            ++len;
        str = new char[len];
        for(size_t i = 0; i != len; ++i){
            str[i] = c[i];
        }
        cap = len;
    }

    string(const string& other){
        
        len = other.len;
        cap = other.cap;
        str = new char[len];

        for(size_t i = 0; i != len; ++i){
            str[i] = other.str[i];
        }
    }

    string& operator=(const string& other){
        // clean up the old str, and allocate a new str big enough to hold the other
        // if other and *this (current string) are the same, run the risk of deallocating other
        // solution: 1) check if(this != &other)
        //           2) change string& operator=(string other)

        if(this != &other){
            delete[] str;
            len = other.len;
            cap = other.cap;
            str = new char[len];

            for(size_t i = 0; i != len; ++i){
                str[i] = other.str[i];
            }
        }

        std::cout << "hei";
        return * this;
    }

    void print(std::ostream & out) const{
        for(size_t i = 0; i != len; ++i){
            out.put(str[i]);
        }
    }

    char& operator[](size_t i){
        return str[i];
    }

    ~string(){
        delete[] str;
    }

};