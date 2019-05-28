//
// Created by dominik on 5/28/19.
//

#ifndef DOMINO_FLOATTYPEVISITOR_H
#define DOMINO_FLOATTYPEVISITOR_H

#include <boost/variant.hpp>

class FloatTypeVisitor: public boost::static_visitor<float>
{
public:
    float operator()(float i) const
    {
        return i;
    }
};


#endif //DOMINO_FLOATTYPEVISITOR_H
