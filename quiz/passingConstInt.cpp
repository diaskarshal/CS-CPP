#include <iostream>

void fun0(int x){
    std::cout << "fun01 " << x << "\n";
    x++;
    std::cout << "fun02 " << x << "\n";
}
void fun1(const int x){
    // x++;
    std::cout << "fun1 " << x << "\n";
}
void fun2(int& x){
    std::cout << "fun21 " << x << "\n";
    x++;
    std::cout << "fun22 " << x << "\n";
}
void fun3(const int& x){
    // x++;
    std::cout << "fun3 " << x << "\n";
}


int main(){
    int i = 10;
    const int ic = 20;
    fun0(i);
    fun0(ic);
    std::cout << "i " << i << "\n";
    std::cout << "ic " << ic << "\n";
    fun1(i);
    fun1(ic);
    fun2(i);
    std::cout << "i " << i << "\n";
    // fun2(ic);
    fun3(i);
    fun3(ic);

}