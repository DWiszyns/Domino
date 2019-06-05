//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_CONDITION_H
#define DOMINO_CONDITION_H


#include "Expression.h"

class Condition {
    std::unique_ptr<Expression> expressionLeft;
    std::unique_ptr<Expression> expressionRight;
    SymbolType relativeOperator;
    bool negative;
public:
    Condition();
    Condition(std::unique_ptr<Expression> expressionLeft, std::unique_ptr<Expression> expressionRight,
            SymbolType relativeOperator,bool negative=false);
    Condition(std::unique_ptr<Expression> expressionLeft, bool expressionRight,
              SymbolType relativeOperator,bool negative=false);
    Condition(Condition &other);
    ~Condition()=default;
    bool evaluate();

};


#endif //DOMINO_CONDITION_H
