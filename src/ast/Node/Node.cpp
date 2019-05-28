#include <utility>

//
// Created by dominik on 5/24/19.
//

#include "Node.h"
/*
Node::Node(ValueType myVariable):myVariable(std::move(myVariable)) {

}
*/
Node::~Node() {

}

/*auto Node::getValue() {
        switch (myVariable.which()){
            case INT:
                int x= boost::apply_visitor(ValueTypeVisitor(),myVariable);
                return x;
        }
    return boost::apply_visitor(ValueTypeVisitor(),myVariable);

}*/
/*
Node::Node(const Node &node):myVariable(node.myVariable) {

}

Node::Node():myVariable(0) {

}

ValueType Node::getMyVariable() {
    return myVariable;
}
*/
auto Node::getValue() {
    return 0;
}

Node::Node(float val):value(val),typeKind(FLOAT) {
}

Node::Node(int val):value(val),typeKind(INT){

}

const Value& Node::getNewValue() const {
    return value;
}

std::ostream &operator<<(std::ostream &os, const Node &obj) {
    Value value =obj.getNewValue();
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

Node::Node(const Rational& val):value(val), typeKind(RATIONAL) {

}

Node::Node(std::string val):value(val), typeKind(STRING){

}

