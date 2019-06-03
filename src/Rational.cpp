//
// Created by dominik on 5/24/19.
//

#include <numeric>
#include "Rational.h"


Rational::Rational(short int numerator, unsigned denominator):numerator(numerator),denominator(denominator) {

}



Rational::~Rational() {

}

Rational::Rational(std::string number) {
    unsigned long position=number.find('.');
    numerator=std::stoi(number.substr(0,position));
    denominator=std::stoi(number.substr(position+1,number.size()-1));
}

Rational::Rational(char *oldNumber) {
    std::string number(oldNumber);
    unsigned long position=number.find('.');
    numerator=std::stoi(number.substr(0,position));
    denominator=std::stoi(number.substr(position+1,number.size()-1));
}


Rational::Rational(const Rational &other):numerator(other.numerator),
    denominator(other.denominator)
    {


}

Rational &Rational::operator=(const Rational& other)
{
    if (this != &other) {
        this->numerator=other.numerator;
        this->denominator=other.denominator;
    }
    return *this;
}

Rational &Rational::operator=(Rational &&other) noexcept {
    if(this != &other) {
        *this=other;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Rational& obj)
{
    os<<obj.numerator<<"."<<obj.denominator<<'r';
    return os;
}

std::istream &operator>>(std::istream &is, Rational &obj) {
    std::string stringRepresentation;
    is>>stringRepresentation;
    obj=stringRepresentation;
    return is;
}

bool Rational::operator==(const Rational &rhs) {
    int gcd=std::gcd(numerator,denominator);
    int otherGcd=std::gcd(rhs.numerator,rhs.denominator);
    return (this->numerator/gcd)==(rhs.numerator/otherGcd)
        &&(this->denominator/gcd)==(rhs.denominator/otherGcd);
}

bool Rational::operator!=(const Rational &rhs) {
    return !(*this==rhs);
}

bool Rational::operator>=(const Rational &rhs) {
    return !(*this < rhs);
}

bool Rational::operator<=(const Rational &rhs) {
    return !(*this > rhs);
}

bool Rational::operator>(const Rational &rhs) {
    Rational ourNumber=shorten(*this);
    Rational otherNumber=shorten(rhs);
    ourNumber.numerator*=otherNumber.denominator;
    otherNumber.numerator*=ourNumber.denominator;
    return ourNumber.numerator>otherNumber.numerator;
}

bool Rational::operator<(const Rational &rhs) {
    return !(*this>rhs||*this==rhs);
}

Rational Rational::operator+(const Rational &rhs) const {
    Rational ourNumber=shorten(*this);
    Rational otherNumber=shorten(rhs);
    ourNumber.numerator*=otherNumber.denominator;
    otherNumber.numerator*=ourNumber.denominator;
    unsigned int commonDenominator=otherNumber.denominator*ourNumber.denominator;
    int newNumerator = ourNumber.numerator+otherNumber.numerator;
    return shorten(Rational(newNumerator, commonDenominator));
}

Rational Rational::operator-(const Rational &rhs) const {
    Rational ourNumber=shorten(*this);
    Rational otherNumber=shorten(rhs);
    ourNumber.numerator*=otherNumber.denominator;
    otherNumber.numerator*=ourNumber.denominator;
    unsigned int commonDenominator=otherNumber.denominator*ourNumber.denominator;
    int newNumerator = ourNumber.numerator-otherNumber.numerator;
    return shorten(Rational(newNumerator, commonDenominator));
}

Rational Rational::operator*(const Rational &rhs) const {
    Rational ourNumber=shorten(*this);
    Rational otherNumber=shorten(rhs);
    return shorten(Rational(ourNumber.numerator*otherNumber.numerator,
    ourNumber.denominator*otherNumber.denominator));
}

Rational Rational::operator/(const Rational &rhs) const {
    Rational ourNumber=shorten(*this);
    Rational otherNumber=shorten(rhs);
    return shorten(Rational(ourNumber.numerator*otherNumber.denominator,
    ourNumber.denominator*otherNumber.numerator));
}

Rational &Rational::operator+=(const Rational &rhs) {
    Rational ourNumber=shorten(*this);
    Rational otherNumber=shorten(rhs);
    ourNumber.numerator*=otherNumber.denominator;
    otherNumber.numerator*=ourNumber.denominator;
    unsigned int commonDenominator=otherNumber.denominator*ourNumber.denominator;
    int newNumerator = ourNumber.numerator+otherNumber.numerator;
    Rational newRational(newNumerator,commonDenominator);
    *this=shorten(newRational);
    return *this;
}

Rational &Rational::operator-=(const Rational &rhs) {
    Rational ourNumber = shorten(*this);
    Rational otherNumber = shorten(rhs);
    ourNumber.numerator *= otherNumber.denominator;
    otherNumber.numerator *= ourNumber.denominator;
    unsigned int commonDenominator = otherNumber.denominator * ourNumber.denominator;
    int newNumerator = ourNumber.numerator - otherNumber.numerator;
    Rational newRational(newNumerator, commonDenominator);
    *this=shorten(newRational);
    return *this;
}

Rational &Rational::operator*=(const Rational &rhs) {
    Rational ourNumber=shorten(*this);
    Rational otherNumber=shorten(rhs);
    *this=shorten( Rational(ourNumber.numerator*otherNumber.numerator,
                            ourNumber.denominator*otherNumber.denominator));
    return *this;
}

Rational &Rational::operator/=(const Rational &rhs) {
    Rational ourNumber=shorten(*this);
    Rational otherNumber=shorten(rhs);
    *this=shorten(Rational(ourNumber.numerator*otherNumber.denominator,
                           ourNumber.denominator*otherNumber.numerator));
    return *this;
}

Rational Rational::shorten(Rational rational) const {
    int gcd=std::gcd(rational.numerator,rational.denominator);
    int numerator = rational.numerator/gcd;
    unsigned int denominator = rational.denominator/gcd;
    return Rational(numerator, denominator);
}

Rational &Rational::operator*() {
    return *this;
}

int Rational::getNumerator() const {
    return numerator;
}

unsigned int Rational::getDenominator() const {
    return denominator;
}

std::string Rational::getRational() const{
    std::string stringRepresentation;
    std::stringstream temp;
    temp<<numerator<<"."<<denominator<<'r';
    stringRepresentation=temp.str();
    return stringRepresentation;
}

Rational::Rational() {
    numerator=0;
    denominator=1;
}



