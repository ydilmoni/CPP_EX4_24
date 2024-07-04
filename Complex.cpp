#include "Complex.hpp"

Complex::Complex(double real, double imaginary)
    : real(real), imaginary(imaginary) {}

double Complex::getReal() const {
    return real;
}

double Complex::getImaginary() const {
    return imaginary;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imaginary - other.imaginary);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imaginary * other.imaginary,
                   real * other.imaginary + imaginary * other.real);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    if (denominator == 0) {
        throw std::invalid_argument("Division by zero.");
    }
    return Complex((real * other.real + imaginary * other.imaginary) / denominator,
                   (imaginary * other.real - real * other.imaginary) / denominator);
}

bool Complex::operator==(const Complex& other) const {
    return real == other.real && imaginary == other.imaginary;
}

std::string Complex::toString() const {
    std::ostringstream oss;
    oss << real << " + " << imaginary << "i";
    return oss.str();
}

std::ostringstream operator<<(std::ostream& os, const Complex& complex) {
    std::ostringstream oss;
    oss << complex.real << " + " << complex.imaginary << "i";
    return oss;
}
