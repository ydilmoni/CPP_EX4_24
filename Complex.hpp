#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <sstream>

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

    // Method to convert Complex to string
    std::string toString() const;

    // Friend function for output stream
    friend std::ostringstream operator<<(std::ostream& os, const Complex& complex);
};

#endif // COMPLEX_H
