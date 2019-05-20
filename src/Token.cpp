//
// Created by dominik on 5/20/19.
//

#include "Token.h"

std::ostream &operator<<(std::ostream &os, Token token) {
    os<<token.getValue();
    return os;
}

std::string Token::getValue() {
    return this->value;
}

SymbolType Token::getType() {
    return this->tokenType;
}

Token::Token(SymbolType tokenType, std::string value):tokenType(tokenType),value(value)
{
}

Token::~Token() {

}
