#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double real, double imaginary);
    
    // Getters
    double getReal() const;
    double getImaginary() const;

    // Overloaded operators
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    bool operator==(const Complex& other) const;

    // Friend function for output stream
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
};

#endif // COMPLEX_HPP
