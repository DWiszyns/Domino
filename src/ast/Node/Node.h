//
// Created by dominik on 5/24/19.
//

#ifndef DOMINO_NODE_H
#define DOMINO_NODE_H

#include <boost/variant.hpp>
#include "../../Rational.h"

/*struct output : public boost::static_visitor<>
{
    template <typename T>
    void operator()(T t) const { std::cout << t << '\n'; }
}; //not sure if I need but might be useful later
 */

enum TypeKind{Int, Rational, Boolean,
    Float, String, Char };

std::string types[6] = { "int","rational",
                         "boolean","float",
                         "string","char"};


typedef boost::variant <int,bool,float,std::string,char,class Rational> ValueType;

class Node {
    ValueType myVariable;//not sure if I need void
//    int value;
public:
    Node(ValueType myVariable);
    ~Node();
    ValueType getValue();

};


#endif //DOMINO_NODE_H
