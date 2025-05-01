#include <iostream>
using namespace std;
int& badFunc() {
    int x = 5;
    return x;  // ERROR: x is destroyed after function returns
}

int main() {
    int x = 42;          // A normal integer variable
    int& ref = x;        // ref is a reference to x
	// int & ref = x;       //they are the same
	// int &ref = x;
	
    cout << "x: " << x << endl; // Output: 42
    cout << "ref: " << ref << endl; // Output: 42

    ref = 10;            // Modifying ref also modifies x
    cout << "x after ref: " << x << endl; // Output: 10
    cout<< badFunc();
    return 0;
}