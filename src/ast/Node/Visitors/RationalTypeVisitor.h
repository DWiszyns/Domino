//
// Created by dominik on 5/28/19.
//

#ifndef DOMINO_RATIONALTYPEVISITOR_H
#define DOMINO_RATIONALTYPEVISITOR_H

#include <boost/variant.hpp>
#include <Rational.h>

class RationalTypeVisitor: public boost::static_visitor<Rational>
{
public:
    Rational operator()(Rational i) const
    {
        return i;
    }
};


#endif //DOMINO_RATIONALTYPEVISITOR_H
