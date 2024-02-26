// Author: Aayush Keshari
// Email: kesharah@mail.uc.edu
// This is the header file (.h) for the ComplexNumbers.cpp
// -------------------------------------------------------------------------
#ifndef COMPLEXNUMBERS_H
#define COMPLEXNUMBERS_H

#include <iostream>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber();  // Default constructor
    ComplexNumber(double real, double imaginary);  // Overloaded constructor

    // Getters and setters
    double getReal() const;
    void setReal(double real);
    double getImaginary() const;
    void setImaginary(double imaginary);

    // Prints the complex number
    void print() const;

    // Operator overloads
    void operator+=(const ComplexNumber& other);
    void operator-=(const ComplexNumber& other);
    void operator*=(double scalar);
    void operator/=(double scalar);
    bool operator==(const ComplexNumber& other) const;
};
// Here, I inserted the perator overloads for +, -, *, /, and <<, as required in Task 3.
ComplexNumber operator+(ComplexNumber lhs, const ComplexNumber& rhs);
ComplexNumber operator-(ComplexNumber lhs, const ComplexNumber& rhs);
ComplexNumber operator*(ComplexNumber complex, double scalar);
ComplexNumber operator*(double scalar, ComplexNumber complex);
ComplexNumber operator/(ComplexNumber complex, double scalar);
std::ostream& operator<<(std::ostream& os, const ComplexNumber& complex);

#endif // COMPLEXNUMBERS_H