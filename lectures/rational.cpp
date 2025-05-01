#include <iostream>
#include <cassert>
#include <numeric>  

class Rational {
private:
    int numerator;
    int denominator;

    void reduce() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    Rational() : numerator(0), denominator(1) {}

    Rational(int num, int den) : numerator(num), denominator(den) {
        assert(den != 0 && "Denominator cannot be zero");
        reduce();
    }

    Rational(const Rational &other)
        : numerator(other.numerator), denominator(other.denominator) {}

    Rational& operator=(const Rational &other) {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }

    // Overloaded addition operator: adds two Rational numbers.
    Rational operator+(const Rational &other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);  // The constructor will reduce the result.
    }

    // Displays the rational number in numerator/denominator form.
    void display() const {
        std::cout << numerator << "/" << denominator;
    }
};

int main() {
    Rational r1(100, 5);
    Rational r2(57, 19);
    Rational r3 = r1 + r2;
    
    std::cout << "Result of addition: ";
    r3.display();
    std::cout << std::endl;
    return 0;
}
