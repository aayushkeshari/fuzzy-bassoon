// Author: Aayush Keshari
// Email: kesharah@mail.uc.edu
// ComplexNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
// -----------------------------------------------------------------------------------------------------

#include <iostream>
#include "ComplexNumbers.h"

ComplexNumber::ComplexNumber() : real(0.0), imaginary(0.0) {}

ComplexNumber::ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary) {}

// This is the implementation of the methods declared in Task 1.
double ComplexNumber::getReal() const {
    return real;
}

void ComplexNumber::setReal(double real) {
    this->real = real;
}

double ComplexNumber::getImaginary() const {
    return imaginary;
}

void ComplexNumber::setImaginary(double imaginary) {
    this->imaginary = imaginary;
}

void ComplexNumber::print() const {
    std::cout << "(" << real << " + " << imaginary << "i)" << std::endl;
}

void ComplexNumber::operator+=(const ComplexNumber& other) {
    real += other.real;
    imaginary += other.imaginary;
}

void ComplexNumber::operator-=(const ComplexNumber& other) {
    real -= other.real;
    imaginary -= other.imaginary;
}

void ComplexNumber::operator*=(double scalar) {
    real *= scalar;
    imaginary *= scalar;
}

void ComplexNumber::operator/=(double scalar) {
    if (scalar != 0.0) {
        real /= scalar;
        imaginary /= scalar;
    }
}

bool ComplexNumber::operator==(const ComplexNumber& other) const {
    return (real == other.real) && (imaginary == other.imaginary);
}

ComplexNumber operator+(ComplexNumber lhs, const ComplexNumber& rhs) {
    lhs += rhs;
    return lhs;
}

ComplexNumber operator-(ComplexNumber lhs, const ComplexNumber& rhs) {
    lhs -= rhs;
    return lhs;
}

ComplexNumber operator*(ComplexNumber complex, double scalar) {
    complex *= scalar;
    return complex;
}

ComplexNumber operator*(double scalar, ComplexNumber complex) {
    complex *= scalar;
    return complex;
}

ComplexNumber operator/(ComplexNumber complex, double scalar) {
    complex /= scalar;
    return complex;
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber& complex) {
    os << "(" << complex.getReal() << " + " << complex.getImaginary() << "i)";
    return os;
}

int main() {
    char choice;

    // This is the code for testing the class, as instructed in Task 4.
    do {
        // Prompts the user for x and y values for the first complex number
        double x1, y1;
        std::cout << "Enter the real part (x1) of the first complex number: ";
        std::cin >> x1;
        std::cout << "Enter the imaginary part (y1) of the first complex number: ";
        std::cin >> y1;

        ComplexNumber c1(x1, y1);

        // Prompts the user for the operation to perform
        char operation;
        std::cout << "Enter the operation (+, -, *, /): ";
        std::cin >> operation;

        // Performs the operation based on user input
        ComplexNumber result;
        double scalar;

        switch (operation) {
        case '+':
        {
            // Prompts the user for x and y values for the second complex number
            double x2, y2;
            std::cout << "Enter the real part (x2) of the second complex number: ";
            std::cin >> x2;
            std::cout << "Enter the imaginary part (y2) of the second complex number: ";
            std::cin >> y2;

            ComplexNumber c2(x2, y2);
            result = c1 + c2;
        }
        break;
        case '-':
        {
            // Prompts the user for x and y values for the second complex number
            double x2, y2;
            std::cout << "Enter the real part (x2) of the second complex number: ";
            std::cin >> x2;
            std::cout << "Enter the imaginary part (y2) of the second complex number: ";
            std::cin >> y2;

            ComplexNumber c2(x2, y2);
            result = c1 - c2;
        }
        break;
        case '*':
            std::cout << "Enter a scalar value: ";
            std::cin >> scalar;
            result = c1 * scalar;
            break;
        case '/':
            std::cout << "Enter a scalar value: ";
            std::cin >> scalar;
            if (scalar != 0.0) {
                result = c1 / scalar;
            }
            else {
                std::cout << "Error encountered! Division by zero!" << std::endl;
            }
            break;
        default:
            std::cout << "Invalid operation." << std::endl;
            continue; // Skips the rest of the loop and asks for continuation
        }

        // Displays the results
        std::cout << "Result: " << result << std::endl;

        // Asks the user if they wish to continue
        std::cout << "Do you wish to continue (y/n)? ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
