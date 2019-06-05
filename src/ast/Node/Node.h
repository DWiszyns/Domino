//
// Created by dominik on 5/24/19.
//

#ifndef DOMINO_NODE_H
#define DOMINO_NODE_H


#include "Value.h"
#include <memory>
#include <string>
#include <vector>



class Node {
    TypeKind typeKind;
    Value value;
    std::string str;
public:
    Node();
    Node(int val);
    Node(float val);
    Node(char val);
    Node(std::string val);
    Node(const Rational& val);
    Node(bool val);
    Node(const Node &node);
    Node(Value value, TypeKind typeKind);
    ~Node();
    const Value& getValue() const;
    const std::string getStr() const;
    const TypeKind getTypeKind() const;
    friend std::ostream& operator<<(std::ostream& os, const Node& obj);
    Node operator+(const Node& rhs);
    Node operator-(const Node& rhs);
    Node operator*(const Node& rhs);
    Node operator/(const Node& rhs);
//    Node&operator+=(const Node& rhs);
//    Node&operator-=(const Node& rhs);
//    Node&operator*=(const Node& rhs);
//    Node&operator/=(const Node& rhs);
    bool operator< (const Node& rhs);
    bool operator> (const Node& rhs);
    bool operator<=(const Node& rhs);
    bool operator>=(const Node& rhs);
    bool operator==(const Node& rhs);
    bool operator!=(const Node& rhs);
    Node& operator=(const Node& other); // copy assignment
    Node& operator=(Node&& other) noexcept; // move assignment
    bool isNumericType() const;


};


#endif //DOMINO_NODE_H
