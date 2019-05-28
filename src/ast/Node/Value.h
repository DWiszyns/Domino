//
// Created by dominik on 5/28/19.
//

#ifndef DOMINO_VALUE_H
#define DOMINO_VALUE_H

#include "../../Rational.h"


enum TypeKind{INT, BOOLEAN,
    FLOAT, STRING, CHAR, RATIONAL};

union Value{
    std::string *str;
    int integer{};
    float floatVal;
    char character;
    Rational *rational;
    bool boolean;

    Value(){
        integer=0;
    }

    explicit Value(const float& x){
        floatVal=x;
    }

    explicit Value(const int& x){
        integer=x;
    }

    explicit Value(const char& x){
        character=x;
    }

    explicit Value(const bool& x){
        boolean=x;
    }
    Value(const Rational& x){

//        const Rational &&y=*x;
//        const Rational *z=&y;
        rational=new Rational(x);
    }

    explicit Value(const std::string& x){
        str=new std::string(x);
    }

    Value(const Value &otherValue, TypeKind typeKind=INT){
        if(typeKind==STRING) str=otherValue.str;
        integer=otherValue.integer;
        floatVal=otherValue.floatVal;
        character=otherValue.character;
        if(typeKind==RATIONAL) rational=new Rational(*(otherValue.rational));
        boolean=otherValue.boolean;
    }
    Value& operator=(const std::string& other)
    {
        str = new std::string(other);
        return *this;
    }

    Value& operator=(const int& other)
    {
        integer = other;
        return *this;
    }

    Value& operator=(const float& other)
    {
        floatVal = other;
        return *this;
    }

    Value& operator=(const Rational& other)
    {
        rational = new Rational(other);
        return *this;
    }

    Value& operator=(const bool& other)
    {
        boolean = other;
        return *this;
    }

    Value& operator=(const char& other)
    {
        character = other;
        return *this;
    }

    Value& operator=(const std::string&& other)
    {
        str = new std::string(other);
        return *this;
    }

    Value& operator=(const int&& other)
    {
        integer = other;
        return *this;
    }

    Value& operator=(const float&& other)
    {
        floatVal = other;
        return *this;
    }

    Value& operator=(const Rational&& other)
    {
        rational = new Rational(other);
        return *this;
    }

    Value& operator=(const bool&& other)
    {
        boolean = other;
        return *this;
    }

    Value& operator=(const char&& other)
    {
        character = other;
        return *this;
    }

    Value& operator=(const Value& otherValue)
    {
        this->str=otherValue.str;
        this->integer=otherValue.integer;
        this->floatVal=otherValue.floatVal;
        this->character=otherValue.character;
        this->rational=otherValue.rational;
        this->boolean=otherValue.boolean;

        return *this;
    }

    Value& operator=(Value&& otherValue)
    {
        if(this!=&otherValue){
            *this=otherValue;
        }

        return *this;
    }


};
#endif //DOMINO_VALUE_H
