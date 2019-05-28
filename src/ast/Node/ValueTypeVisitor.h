//
// Created by dominik on 5/27/19.
//

#ifndef DOMINO_VALUETYPEVISITOR_H
#define DOMINO_VALUETYPEVISITOR_H

#include <boost/variant.hpp>
#include "../../Rational.h"

typedef boost::variant <float,Rational> ValueType;



#endif //DOMINO_VALUETYPEVISITOR_H
