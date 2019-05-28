//
// Created by dominik on 5/28/19.
//

#ifndef DOMINO_INTTYPEVISITOR_H
#define DOMINO_INTTYPEVISITOR_H

#include <boost/variant.hpp>


class IntTypeVisitor: public boost::static_visitor<int>
{
public:
    int operator()(int i) const
    {
        return i;
    }

};

#endif //DOMINO_INTTYPEVISITOR_H
