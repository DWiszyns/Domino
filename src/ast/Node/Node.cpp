#include <utility>

//
// Created by dominik on 5/24/19.
//

#include "Node.h"

Node::Node() {

}

Node::~Node() {

}

auto Node::getValue() {
    return 0;
}

Node::Node(float val):value(val),typeKind(FLOAT) {
}

Node::Node(int val):value(val),typeKind(INT){

}

Node::Node(const Rational& val):value(val), typeKind(RATIONAL) {

}

Node::Node(std::string val):value(val), typeKind(STRING){

}

Node::Node(char val):value(val), typeKind(CHAR) {

}


Node::Node(bool val):value(val),typeKind(BOOLEAN) {

}

Node::Node(const Node &node):value(node.value,node.typeKind),typeKind(node.typeKind) {

}

Node::Node(Value value, TypeKind typeKind):value(value,typeKind),typeKind(typeKind) {

}



const Value& Node::getNewValue() const {
    return value;
}

std::ostream &operator<<(std::ostream &os, const Node &obj) {
    Value value(obj.getNewValue(),obj.typeKind);
    switch(obj.getTypeKind()){
        case INT:
        {
            os<<value.integer;
            break;
        }
        case STRING:{
            os<<obj.getNewValue().str;
            break;}
        case FLOAT:{
            os<<obj.getNewValue().floatVal;
            break;}
        case RATIONAL:{
            os<<obj.getNewValue().rational;
            break;}
        case CHAR:{
            os<<obj.getNewValue().character;
            break;}
        case BOOLEAN:{
            os<<obj.getNewValue().boolean;
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
    Value newValue;
    TypeKind typeKind;
    if(this->isNumericType()&&rhs.isNumericType()){
        if(this->typeKind==INT&&rhs.typeKind==INT){
            int x= this->getNewValue().integer+rhs.getNewValue().integer;
            newValue.integer=x;
            typeKind=INT;
        }
        else if (this->typeKind==INT&&rhs.typeKind==FLOAT){
            float x= this->getNewValue().integer+rhs.getNewValue().floatVal;
            newValue.floatVal=x;
            typeKind=FLOAT;
        }
        else if (this->typeKind==FLOAT&&rhs.typeKind==INT){
            float x= this->getNewValue().floatVal+rhs.getNewValue().integer;
            newValue.floatVal=x;
            typeKind=FLOAT;
        }
        else if(this->typeKind==FLOAT&&rhs.typeKind==FLOAT){
            float x= rhs.getNewValue().floatVal+this->getNewValue().floatVal;
            newValue.floatVal=x;
            typeKind=FLOAT;
        }
        else if(this->typeKind==FLOAT&&rhs.typeKind==RATIONAL){
            float temp=rhs.getNewValue().rational->getNumerator()/rhs.getNewValue().rational->getDenominator();
            float x= temp+this->getNewValue().floatVal;
            newValue.floatVal=x;
            typeKind=FLOAT;
        }
        else if (this->typeKind==INT&&rhs.typeKind==RATIONAL){
            Rational x= Rational(rhs.getNewValue().integer,1);+rhs.getNewValue().floatVal;
            newValue.rational=&x;
            typeKind=RATIONAL;
        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==FLOAT){
            float temp=this->getNewValue().rational->getNumerator()/this->getNewValue().rational->getDenominator();
            float x= temp+rhs.getNewValue().floatVal;
            newValue.floatVal=x;
            typeKind=FLOAT;
        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==INT){
            Rational x= *(this->getNewValue().rational)+Rational(rhs.getNewValue().integer,1);
            newValue.rational=&x;
            typeKind=RATIONAL;
        }
        else if(this->typeKind==RATIONAL&&rhs.typeKind==RATIONAL){
            Rational x= *(this->getNewValue().rational)+*(rhs.getNewValue().rational);
            newValue.rational=&x;
            typeKind=RATIONAL;
        }
        return Node(newValue,typeKind);
    }
    return Node(0);
}

bool Node::isNumericType() const {
    return this->typeKind==INT || this->typeKind==FLOAT || this->typeKind==RATIONAL;
}








