//
// Created by dominik on 5/24/19.
//

#ifndef DOMINO_NODE_H
#define DOMINO_NODE_H


#include "ValueTypeVisitor.h"


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

//        const Rational &&y=*x;
//        const Rational *z=&y;
        rational=new Rational(x);
    }

    explicit Value(const std::string& x){
        str=new std::string(x);
    }

    Value(const Value &otherValue){
        this->str=otherValue.str;
        this->integer=otherValue.integer;
        this->floatVal=otherValue.floatVal;
        this->character=otherValue.character;
        this->rational=otherValue.rational;
        this->boolean=otherValue.boolean;

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

    /*Value& operator=(const std::string&& other)
    {
        str = other;
        return *this;
    }*/

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

class Node {
    TypeKind typeKind;
    Value value;
    ValueType myVariable;//not sure if I need void
//    int value;
public:
    Node();
    Node(ValueType myVariable);
   // Node(Value val);
    Node(int val);
    Node(float val);
    Node(char val);
    Node(std::string val);
    Node(const Rational& val);
    Node(bool val);
    Node(const Node &node);
    ~Node();
    auto getValue();
    const Value& getNewValue() const;
    ValueType getMyVariable();
    const TypeKind getTypeKind() const;
    friend std::ostream& operator<<(std::ostream& os, const Node& obj);


};


#endif //DOMINO_NODE_H
