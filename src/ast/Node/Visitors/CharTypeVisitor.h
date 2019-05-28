//
// Created by dominik on 5/28/19.
//

#ifndef DOMINO_CHARTYPEVISITOR_H
#define DOMINO_CHARTYPEVISITOR_H

#include <boost/variant.hpp>

class CharTypeVisitor: public boost::static_visitor<char>
{
public:
    char operator()(const char cr) const
    {
        return cr;
    }
};

#endif //DOMINO_CHARTYPEVISITOR_H
