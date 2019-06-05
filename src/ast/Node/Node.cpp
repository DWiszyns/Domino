#include <utility>

//
// Created by dominik on 5/24/19.
//

#include "Node.h"


Node::Node() {

}

Node::~Node() {

}

Node::Node(float val):value(val),typeKind(FLOAT) {
}

Node::Node(int val):value(val),typeKind(INT){

}

Node::Node(const Rational& val):value(val), typeKind(RATIONAL) {

}

Node::Node(std::string val): typeKind(STRING),str(std::move(val)){
}

Node::Node(char val):value(val), typeKind(CHAR) {

}


Node::Node(bool val):value(val),typeKind(BOOLEAN) {

}

Node::Node(const Node &node):value(node.value,node.typeKind),typeKind(node.typeKind),str(node.str) {

}

Node::Node(Value value, TypeKind typeKind):value(value,typeKind),typeKind(typeKind) {

}



const Value& Node::getValue() const {
    return value;
}

std::ostream &operator<<(std::ostream &os, const Node &obj) {
    Value value(obj.getValue(),obj.typeKind);
    switch(obj.getTypeKind()){
        case INT:{
            os<<value.integer;
            break;
        }
        case STRING:{
            os<<obj.str;
            break;}
        case FLOAT:{
            os<< obj.getValue().floatVal;
            break;}
        case RATIONAL:{
            os<< obj.getValue().rational.getRational();
            break;}
        case CHAR:{
            os<< obj.getValue().character;
            break;}
        case BOOLEAN:{
            os<< obj.getValue().boolean;
            break;}
        default:break;

    }
    return os;
}

const TypeKind Node::getTypeKind() const{
    return typeKind;
}

//we'll do checking expressions in parser
Node Node::operator+(const Node &rhs) {
    if(this->isNumericType()&&rhs.isNumericType()){
        if(this->typeKind==INT&&rhs.typeKind==INT){
            int x= this->getValue().integer+ rhs.getValue().integer;
            return Node(x);
        }
        else if (this->typeKind==INT&&rhs.typeKind==FLOAT){
            float x= this->getValue().integer+ rhs.getValue().floatVal;
            return Node(x);
        }
        else if (this->typeKind==FLOAT&&rhs.typeKind==INT){
            float x= this->getValue().floatVal+ rhs.getValue().integer;
            return Node(x);
        }
        else if(this->typeKind==FLOAT&&rhs.typeKind==FLOAT){
            float x= rhs.getValue().floatVal+ this->getValue().floatVal;
            return Node(x);
        }
        else if(this->typeKind==FLOAT&&rhs.typeKind==RATIONAL){
            float temp=(float) rhs.getValue().rational.getNumerator()/ rhs.getValue().rational.getDenominator();
            float x= temp+ this->getValue().floatVal;
            return Node(x);
        }
        else if (this->typeKind==INT&&rhs.typeKind==RATIONAL){
            Rational x= Rational(this->getValue().integer,1)+ rhs.getValue().rational;
            return Node(x);
        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==FLOAT){
            float temp=(float) this->getValue().rational.getNumerator()/ this->getValue().rational.getDenominator();
            float x= temp+ rhs.getValue().floatVal;
            return Node(x);

        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==INT){
            Rational x= Rational(rhs.getValue().integer,1)+ this->getValue().rational;
            return Node(x);

        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==RATIONAL){
            Rational x= this->getValue().rational+ rhs.getValue().rational;
            return Node(x);
        }
    }
    return Node(0);
}

bool Node::isNumericType() const {
    return this->typeKind==INT || this->typeKind==FLOAT || this->typeKind==RATIONAL;
}

Node Node::operator-(const Node &rhs) {
    if(this->isNumericType()&&rhs.isNumericType()){
        if(this->typeKind==INT&&rhs.typeKind==INT){
            int x= this->getValue().integer- rhs.getValue().integer;
            return Node(x);
        }
        else if (this->typeKind==INT&&rhs.typeKind==FLOAT){
            float x= this->getValue().integer- rhs.getValue().floatVal;
            return Node(x);
        }
        else if (this->typeKind==FLOAT&&rhs.typeKind==INT){
            float x= this->getValue().floatVal- rhs.getValue().integer;
            return Node(x);
        }
        else if(this->typeKind==FLOAT&&rhs.typeKind==FLOAT){
            float x= this->getValue().floatVal- rhs.getValue().floatVal;
            return Node(x);
        }
        else if(this->typeKind==FLOAT&&rhs.typeKind==RATIONAL){
            float temp=(float) rhs.getValue().rational.getNumerator()/ rhs.getValue().rational.getDenominator();
            float x= this->getValue().floatVal-temp;
            return Node(x);
        }
        else if (this->typeKind==INT&&rhs.typeKind==RATIONAL){
            Rational x= Rational(this->getValue().integer,1)- rhs.getValue().rational;
            return Node(x);
        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==FLOAT){
            float temp=(float) this->getValue().rational.getNumerator()/ this->getValue().rational.getDenominator();
            float x= temp- rhs.getValue().floatVal;
            return Node(x);

        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==INT){
            Rational x= this->getValue().rational-Rational(rhs.getValue().integer,1);
            return Node(x);

        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==RATIONAL){
            Rational x= this->getValue().rational- rhs.getValue().rational;
            return Node(x);
        }
    }
    return Node(0);
}

Node Node::operator*(const Node &rhs) {
    if(this->isNumericType()&&rhs.isNumericType()){
        if(this->typeKind==INT&&rhs.typeKind==INT){
            int x= this->getValue().integer* rhs.getValue().integer;
            return Node(x);
        }
        else if (this->typeKind==INT&&rhs.typeKind==FLOAT){
            float x= this->getValue().integer* rhs.getValue().floatVal;
            return Node(x);
        }
        else if (this->typeKind==FLOAT&&rhs.typeKind==INT){
            float x= this->getValue().floatVal* rhs.getValue().integer;
            return Node(x);
        }
        else if(this->typeKind==FLOAT&&rhs.typeKind==FLOAT){
            float x= this->getValue().floatVal* rhs.getValue().floatVal;
            return Node(x);
        }
        else if(this->typeKind==FLOAT&&rhs.typeKind==RATIONAL){
            float temp=(float) rhs.getValue().rational.getNumerator()/ rhs.getValue().rational.getDenominator();
            float x= this->getValue().floatVal*temp;
            return Node(x);
        }
        else if (this->typeKind==INT&&rhs.typeKind==RATIONAL){
            Rational x= Rational(this->getValue().integer,1)*(rhs.getValue().rational);
            return Node(x);
        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==FLOAT){
            float temp=(float) this->getValue().rational.getNumerator()/ this->getValue().rational.getDenominator();
            float x= temp* rhs.getValue().floatVal;
            return Node(x);

        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==INT){
            Rational x= (this->getValue().rational)*Rational(rhs.getValue().integer,1);
            return Node(x);

        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==RATIONAL){
            Rational x= (this->getValue().rational)*(rhs.getValue().rational);
            return Node(x);
        }
    }
    return Node(0);
}

Node Node::operator/(const Node &rhs) {
    if(this->isNumericType()&&rhs.isNumericType()){
        if(this->typeKind==INT&&rhs.typeKind==INT){
            int x= this->getValue().integer/ rhs.getValue().integer;
            return Node(x);
        }
        else if (this->typeKind==INT&&rhs.typeKind==FLOAT){
            float x= this->getValue().integer/ rhs.getValue().floatVal;
            return Node(x);
        }
        else if (this->typeKind==FLOAT&&rhs.typeKind==INT){
            float x= this->getValue().floatVal/ rhs.getValue().integer;
            return Node(x);
        }
        else if(this->typeKind==FLOAT&&rhs.typeKind==FLOAT){
            float x= this->getValue().floatVal/ rhs.getValue().floatVal;
            return Node(x);
        }
        else if(this->typeKind==FLOAT&&rhs.typeKind==RATIONAL){
            float temp=(float) rhs.getValue().rational.getNumerator()/ rhs.getValue().rational.getDenominator();
            float x= this->getValue().floatVal/temp;
            return Node(x);
        }
        else if (this->typeKind==INT&&rhs.typeKind==RATIONAL){
            Rational x= Rational(this->getValue().integer,1)/(rhs.getValue().rational);
            return Node(x);
        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==FLOAT){
            float temp=(float) this->getValue().rational.getNumerator()/ this->getValue().rational.getDenominator();
            float x= temp/ rhs.getValue().floatVal;
            return Node(x);

        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==INT){
            Rational x= (this->getValue().rational)/Rational(rhs.getValue().integer,1);
            return Node(x);

        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==RATIONAL){
            Rational x= (this->getValue().rational)/(rhs.getValue().rational);
            return Node(x);
        }
    }
    return Node(0);
}

Node &Node::operator=(const Node &other) {
    if (this != &other) {
        this->value=other.getValue();
        this->typeKind=other.typeKind;
    }
    return *this;
}

Node &Node::operator=(Node &&other) noexcept {
    if(this != &other) {
        *this=other;
    }
    return *this;
}

const std::string Node::getStr() const {
    return str;
}


bool Node::operator<(const Node &rhs) {
    if(this->isNumericType()&&rhs.isNumericType()){
        if(this->typeKind==INT&&rhs.typeKind==INT){
            return this->getValue().integer < rhs.getValue().integer;
        }
        else if (this->typeKind==INT&&rhs.typeKind==FLOAT){
            return this->getValue().integer < rhs.getValue().floatVal;
        }
        else if (this->typeKind==FLOAT&&rhs.typeKind==INT){
            return this->getValue().floatVal < rhs.getValue().integer;
        }
        else if(this->typeKind==FLOAT&&rhs.typeKind==FLOAT){
            return this->getValue().floatVal < rhs.getValue().floatVal;
        }
        else if(this->typeKind==FLOAT&&rhs.typeKind==RATIONAL){
            float temp=(float) rhs.getValue().rational.getNumerator()/ rhs.getValue().rational.getDenominator();
            return this->getValue().floatVal < temp;
        }
        else if (this->typeKind==INT&&rhs.typeKind==RATIONAL){
            return Rational(this->getValue().integer,1)<(rhs.getValue().rational);
        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==FLOAT){
            float temp=(float) this->getValue().rational.getNumerator()/ this->getValue().rational.getDenominator();
            return temp < rhs.getValue().floatVal;
        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==INT){
            return  (this->getValue().rational) < Rational(rhs.getValue().integer,1);
        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==RATIONAL){
            return (this->getValue().rational) < (rhs.getValue().rational);
        }
    }
    return false;
}

bool Node::operator==(const Node &rhs) {
    if(this->isNumericType()&&rhs.isNumericType()){
        if(this->typeKind==INT&&rhs.typeKind==INT){
            return this->getValue().integer == rhs.getValue().integer;
        }
        else if (this->typeKind==INT&&rhs.typeKind==FLOAT){
            return this->getValue().integer == rhs.getValue().floatVal;
        }
        else if (this->typeKind==FLOAT&&rhs.typeKind==INT){
            return this->getValue().floatVal == rhs.getValue().integer;
        }
        else if(this->typeKind==FLOAT&&rhs.typeKind==FLOAT){
            return this->getValue().floatVal == rhs.getValue().floatVal;
        }
        else if(this->typeKind==FLOAT&&rhs.typeKind==RATIONAL){
            float temp=(float) rhs.getValue().rational.getNumerator()/ rhs.getValue().rational.getDenominator();
            return this->getValue().floatVal == temp;
        }
        else if (this->typeKind==INT&&rhs.typeKind==RATIONAL){
            return Rational(this->getValue().integer,1)==(rhs.getValue().rational);
        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==FLOAT){
            float temp=(float) this->getValue().rational.getNumerator()/ this->getValue().rational.getDenominator();
            return temp == rhs.getValue().floatVal;
        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==INT){
            return (this->getValue().rational) == Rational(rhs.getValue().integer,1);

        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==RATIONAL){
            return (this->getValue().rational) == (rhs.getValue().rational);
        }
    }
    else{
        if(this->typeKind!=rhs.typeKind) return false;
        else switch (typeKind)
            {
                case STRING: return (this->str==rhs.str);
                case CHAR: return this->getValue().character==rhs.getValue().character;
                case BOOLEAN: return this->getValue().boolean == rhs.getValue().boolean;
                default:return false;
            }
    }
}

bool Node::operator>(const Node &rhs){
    return !(*this==rhs || *this<rhs);
}

bool Node::operator>=(const Node &rhs) {
    return !(*this<rhs);
}

bool Node::operator!=(const Node &rhs) {
    return  !(*this==rhs);
}

bool Node::operator<=(const Node &rhs) {
    return !(*this>rhs);
}









