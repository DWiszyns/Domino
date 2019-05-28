//
// Created by dominik on 5/28/19.
//

#ifndef DOMINO_BOOLTYPEVISITOR_H
#define DOMINO_BOOLTYPEVISITOR_H

#include <boost/variant.hpp>

class BoolTypeVisitor: public boost::static_visitor<bool>
{
public:

    BoolTypeVisitor() = default;

    bool operator()(bool bl) const
    {
        return bl;
    }

};

#endif //DOMINO_BOOLTYPEVISITOR_H
