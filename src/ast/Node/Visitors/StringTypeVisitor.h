//
// Created by dominik on 5/28/19.
//

#ifndef DOMINO_STRINGTYPEVISITOR_H
#define DOMINO_STRINGTYPEVISITOR_H

#include <boost/variant.hpp>

class StringTypeVisitor: public boost::static_visitor<std::string>
{
public:
    std::string operator()(const std::string & str) const
    {
        return str;
    }

};


#endif //DOMINO_STRINGTYPEVISITOR_H
