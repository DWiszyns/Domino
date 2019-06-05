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
    Rational shorten(Rational rational) const;
public:
    Rational();
    Rational(short int numerator,unsigned denominator);
    Rational(std::string number);
    Rational(char* number);
    Rational(const Rational& other);
    ~Rational();
    int getNumerator() const;
    unsigned int getDenominator() const;
    std::string getRational() const;
    friend std::ostream& operator<<(std::ostream& os, const Rational& obj);
    friend std::istream& operator>>(std::istream& is, Rational& obj);
    Rational& operator=(const Rational& other); // copy assignment
    Rational& operator=(Rational&& other) noexcept; // move assignment
    Rational& operator* ();
    bool operator< (const Rational& rhs)const;
    bool operator> (const Rational& rhs)const;
    bool operator<=(const Rational& rhs)const;
    bool operator>=(const Rational& rhs)const;
    bool operator==(const Rational& rhs)const;
    bool operator!=(const Rational& rhs)const;
    Rational operator+(const Rational& rhs) const;
    Rational operator-(const Rational& rhs) const;
    Rational operator*(const Rational& rhs) const;
    Rational operator/(const Rational& rhs) const;
    Rational&operator+=(const Rational& rhs);
    Rational&operator-=(const Rational& rhs);
    Rational&operator*=(const Rational& rhs);
    Rational&operator/=(const Rational& rhs);

};


#endif //DOMINO_RATIONAL_H
