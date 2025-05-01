#include <iostream>

class cat{
public:

    cat(){
        std::cout << "Tom";
    }

    cat(std::string str){
        std::cout << str;
    }

    cat(const cat &c){
        std::cout << "Tiger";
    }

    cat& operator=(const cat &c){
        std::cout << "Mittens";
        return * this;
    }
};

class dog{
public:

    dog(){
        std::cout << "Fido";
    }

    dog(const dog &d){
        std::cout << "Ralph";
    }

    dog(cat c){
        std::cout << "Brutus";
    }
};

int main(){
    cat c1("Felix");
    dog d1;
    cat c2=c1;
    dog d2(c1);
    dog d3(d2);
}