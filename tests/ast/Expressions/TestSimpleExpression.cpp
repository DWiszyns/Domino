//
// Created by dominik on 5/27/19.
//

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <ast/Variable.h>
#include "ast/Expression/SimpleExpression.h"

BOOST_AUTO_TEST_SUITE(SimpleExpressionsTest)

    BOOST_AUTO_TEST_CASE(simpleExpression_with_one_int){
        int x=7;
        Node n(x);
        ValueFactor myFactor(n);
        std::list<std::unique_ptr<Factor>> factorsList;
        factorsList.push_back(std::make_unique<ValueFactor>(std::move(myFactor)));
        std::list<SymbolType> symbols;
        SimpleExpression simpleExpression(std::move(factorsList),symbols);
        BOOST_CHECK_EQUAL(simpleExpression.execute().getValue().integer,7);
        BOOST_CHECK_EQUAL(simpleExpression.execute().getTypeKind(),INT);
    }

    BOOST_AUTO_TEST_CASE(simpleexpression_with_multiple_ints){
        std::list<std::unique_ptr<Factor>> factorsList;
        factorsList.push_back(std::make_unique<ValueFactor>(7));
        factorsList.push_back(std::make_unique<ValueFactor>(8));
        factorsList.push_back(std::make_unique<ValueFactor>(4));
        std::list<SymbolType> symbols;
        symbols.push_back(MULTIPLYSY);
        symbols.push_back(DIVIDESY);
        SimpleExpression simpleExpression(std::move(factorsList),symbols);
        BOOST_CHECK_EQUAL(simpleExpression.execute().getValue().integer,14);
        BOOST_CHECK_EQUAL(simpleExpression.execute().getTypeKind(),INT);
    }

    BOOST_AUTO_TEST_CASE(simpleexpression_with_multiple_floats){
        std::list<std::unique_ptr<Factor>> factorsList;
        factorsList.push_back(std::make_unique<ValueFactor>(7.0f));
        factorsList.push_back(std::make_unique<ValueFactor>(8.0f));
        factorsList.push_back(std::make_unique<ValueFactor>(4.0f));
        std::list<SymbolType> symbols;
        symbols.push_back(MULTIPLYSY);
        symbols.push_back(DIVIDESY);
        SimpleExpression simpleExpression(std::move(factorsList),symbols);
        BOOST_CHECK_EQUAL(simpleExpression.execute().getValue().floatVal,14.0f);
        BOOST_CHECK_EQUAL(simpleExpression.execute().getTypeKind(),FLOAT);
    }

    BOOST_AUTO_TEST_CASE(simpleexpression_with_multiple_rationals){
        std::list<std::unique_ptr<Factor>> factorsList;
        Rational x("7.1r");
        Rational y("8.1r");
        Rational z("4.1r");
        factorsList.push_back(std::make_unique<ValueFactor>(Node(x)));
        factorsList.push_back(std::make_unique<ValueFactor>(Node(y)));
        factorsList.push_back(std::make_unique<ValueFactor>(Node(z)));
        std::list<SymbolType> symbols;
        symbols.push_back(MULTIPLYSY);
        symbols.push_back(DIVIDESY);
        SimpleExpression simpleExpression(std::move(factorsList),symbols);
        BOOST_CHECK_EQUAL(simpleExpression.execute().getTypeKind(),RATIONAL);
        BOOST_CHECK_EQUAL(simpleExpression.execute().getValue().rational.getRational(),"14.1r");
    }


    BOOST_AUTO_TEST_CASE(simpleexpression_with_multiple_types){
        std::list<std::unique_ptr<Factor>> factorsList;
        factorsList.push_back(std::make_unique<ValueFactor>(7));
        factorsList.push_back(std::make_unique<ValueFactor>(8.0f));
        factorsList.push_back(std::make_unique<ValueFactor>(Rational("4.1r")));
        std::list<SymbolType> symbols;
        symbols.push_back(MULTIPLYSY);
        symbols.push_back(DIVIDESY);
        SimpleExpression simpleExpression(std::move(factorsList),symbols);
        BOOST_CHECK_EQUAL(simpleExpression.execute().getValue().floatVal,14.0f);
        BOOST_CHECK_EQUAL(simpleExpression.execute().getTypeKind(),FLOAT);
    }

BOOST_AUTO_TEST_SUITE_END()