//
// Created by dominik on 5/24/19.
//

#ifndef DOMINO_RATIONAL_H
#define DOMINO_RATIONAL_H


//#include <iostream>
#include <sstream>

class Rational {
    int numerator;
    unsigned int denominator;
    std::string stringRepresentation;
    Rational shorten(Rational rational);
public:
    Rational();
    Rational(short int numerator,unsigned denominator);
    Rational(std::string number);
    Rational(char* number);
    Rational(const Rational& other);
    ~Rational();
    int getNumerator();
    unsigned int getDenominator();
    std::string getRational() const;
    friend std::ostream& operator<<(std::ostream& os, const Rational& obj);
    friend std::istream& operator>>(std::istream& is, Rational& obj);
    Rational& operator=(const Rational& other); // copy assignment
    Rational& operator=(Rational&& other) noexcept; // move assignment
    Rational& operator* ();
    bool operator< (const Rational& rhs);
    bool operator> (const Rational& rhs);
    bool operator<=(const Rational& rhs);
    bool operator>=(const Rational& rhs);
    bool operator==(const Rational& rhs);
    bool operator!=(const Rational& rhs);
    Rational operator+(const Rational& rhs);
    Rational operator-(const Rational& rhs);
    Rational operator*(const Rational& rhs);
    Rational operator/(const Rational& rhs);
    Rational&operator+=(const Rational& rhs);
    Rational&operator-=(const Rational& rhs);
    Rational&operator*=(const Rational& rhs);
    Rational&operator/=(const Rational& rhs);

};


#endif //DOMINO_RATIONAL_H
