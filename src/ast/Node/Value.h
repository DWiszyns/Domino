//
// Created by dominik on 5/28/19.
//

#ifndef DOMINO_VALUE_H
#define DOMINO_VALUE_H

#include "../../Rational.h"
#include<memory>


enum TypeKind{INT, BOOLEAN,
    FLOAT, STRING, CHAR, RATIONAL};

union Value{
    int integer{};
    float floatVal;
    char character;
    Rational rational;
    bool boolean;

    Value(){
        integer=0;
    }
    ~Value(){
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

        rational=x;
    }

    Value(const Value &otherValue, TypeKind typeKind=INT){
        integer=otherValue.integer;
        floatVal=otherValue.floatVal;
        character=otherValue.character;
        rational=otherValue.rational;
        boolean=otherValue.boolean;
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
        rational = other;
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
        rational = other;
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
