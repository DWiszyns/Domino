//
// Created by dominik on 5/29/19.
//

//
// Created by dominik on 5/27/19.
//

#include <boost/test/unit_test.hpp>
#include <iostream>
#include "ast/Statements/Assignment.h"

BOOST_AUTO_TEST_SUITE(AssignmentsTest)

    BOOST_AUTO_TEST_CASE(expression_with_one_int){
        std::list<std::unique_ptr<Factor>> factorsList;
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(7)));
        std::list<SymbolType> symbols;
        std::list<std::unique_ptr<SimpleExpression>> simpleExpressions;
        std::list<SymbolType> addSymbols;
        SimpleExpression simpleExpression(std::move(factorsList),symbols);
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpression)));
        Expression expression(std::move(simpleExpressions),addSymbols);
        std::vector<std::shared_ptr<Node>> nodes;
        nodes.push_back(std::make_shared<Node>(8));
        Variable myVariable("myVariable",std::move(nodes),1);
        Assignment assignment(&myVariable,std::make_unique<Expression>(expression),0);
        assignment.execute();
        BOOST_CHECK_EQUAL(myVariable.isSingleNode(),true);
        BOOST_CHECK_EQUAL(myVariable.getName(),"myVariable");
        BOOST_CHECK_EQUAL(myVariable.getNode().getValue().integer,7);
        BOOST_CHECK_EQUAL(myVariable.getNode().getTypeKind(),INT);
}

    BOOST_AUTO_TEST_CASE(expression_with_multiple_ints){
        std::list<std::unique_ptr<Factor>> factorsList;
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(7)));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(8)));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(4)));
        std::list<SymbolType> symbols;
        symbols.push_back(MULTIPLY);
        symbols.push_back(DIVIDE);
        SimpleExpression simpleExpression(std::move(factorsList),symbols);
        std::list<std::unique_ptr<SimpleExpression>> simpleExpressions;
        std::list<SymbolType> addSymbols;
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpression)));
        Expression expression(std::move(simpleExpressions),addSymbols);
        std::vector<std::shared_ptr<Node>> nodes;
        nodes.push_back(std::make_shared<Node>(8));
        Variable myVariable("myVariable",std::move(nodes),1);
        Assignment assignment(&myVariable,std::make_unique<Expression>(expression),0);
        assignment.execute();
        BOOST_CHECK_EQUAL(myVariable.isSingleNode(),true);
        BOOST_CHECK_EQUAL(myVariable.getName(),"myVariable");
        BOOST_CHECK_EQUAL(myVariable.getNode().getValue().integer,14);
        BOOST_CHECK_EQUAL(myVariable.getNode().getTypeKind(),INT);
}

    BOOST_AUTO_TEST_CASE(expression_with_multiple_floats){
        std::list<std::unique_ptr<Factor>> factorsList;
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(7.0f)));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(8.0f)));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(4.0f)));
        std::list<SymbolType> symbols;
        symbols.push_back(MULTIPLY);
        symbols.push_back(DIVIDE);
        SimpleExpression simpleExpression(std::move(factorsList),symbols);
        std::list<std::unique_ptr<SimpleExpression>> simpleExpressions;
        std::list<SymbolType> addSymbols;
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpression)));
        Expression expression(std::move(simpleExpressions),addSymbols);
        std::vector<std::shared_ptr<Node>> nodes;
        nodes.push_back(std::make_shared<Node>(8));
        Variable myVariable("myVariable",std::move(nodes),1);
        Assignment assignment(&myVariable,std::make_unique<Expression>(expression),0);
        assignment.execute();
        BOOST_CHECK_EQUAL(myVariable.isSingleNode(),true);
        BOOST_CHECK_EQUAL(myVariable.getName(),"myVariable");
        BOOST_CHECK_EQUAL(myVariable.getNode().getValue().floatVal,14.0f);
        BOOST_CHECK_EQUAL(myVariable.getNode().getTypeKind(),FLOAT);
}

    BOOST_AUTO_TEST_CASE(expression_with_multiple_rationals){
        std::list<std::unique_ptr<Factor>> factorsList;
        Rational x("7.1r");
        Rational y("8.1r");
        Rational z("4.1r");
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(Node(x))));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(Node(y))));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(Node(z))));
        std::list<SymbolType> symbols;
        symbols.push_back(MULTIPLY);
        symbols.push_back(DIVIDE);
        SimpleExpression simpleExpression(std::move(factorsList),symbols);
        std::list<std::unique_ptr<SimpleExpression>> simpleExpressions;
        std::list<SymbolType> addSymbols;
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpression)));
        Expression expression(std::move(simpleExpressions),addSymbols);
        std::vector<std::shared_ptr<Node>> nodes;
        nodes.push_back(std::make_shared<Node>(8));
        Variable myVariable("myVariable",std::move(nodes),1);
        Assignment assignment(&myVariable,std::make_unique<Expression>(expression),0);
        assignment.execute();
        BOOST_CHECK_EQUAL(myVariable.isSingleNode(),true);
        BOOST_CHECK_EQUAL(myVariable.getName(),"myVariable");
        BOOST_CHECK_EQUAL(myVariable.getNode().getValue().rational.getRational(),"14.1r");
        BOOST_CHECK_EQUAL(myVariable.getNode().getTypeKind(),RATIONAL);
}


    BOOST_AUTO_TEST_CASE(expression_with_multiple_types){
        std::list<std::unique_ptr<Factor>> factorsList;
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(7)));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(8.0f)));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(Rational("4.1r"))));
        std::list<SymbolType> symbols;
        symbols.push_back(MULTIPLY);
        symbols.push_back(DIVIDE);
        SimpleExpression simpleExpression(std::move(factorsList),symbols);
        std::list<std::unique_ptr<SimpleExpression>> simpleExpressions;
        std::list<SymbolType> addSymbols;
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpression)));
        Expression expression(std::move(simpleExpressions),addSymbols);
        std::vector<std::shared_ptr<Node>> nodes;
        nodes.push_back(std::make_shared<Node>(8));
        Variable myVariable("myVariable",std::move(nodes),1);
        Assignment assignment(&myVariable,std::make_unique<Expression>(expression),0);
        assignment.execute();
        BOOST_CHECK_EQUAL(myVariable.isSingleNode(),true);
        BOOST_CHECK_EQUAL(myVariable.getName(),"myVariable");
        BOOST_CHECK_EQUAL(myVariable.getNode().getValue().floatVal,14.0f);
        BOOST_CHECK_EQUAL(myVariable.getNode().getTypeKind(),FLOAT);
}

    BOOST_AUTO_TEST_CASE(expression_with_adding_two_simpleexpressions){
        std::list<std::unique_ptr<Factor>> factorsList;
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(7)));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(8.0f)));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(Rational("4.1r"))));
        std::list<SymbolType> symbols;
        symbols.push_back(MULTIPLY);
        symbols.push_back(DIVIDE);
        SimpleExpression simpleExpression(std::move(factorsList),symbols);

        std::list<std::unique_ptr<Factor>> factorsList2;
        factorsList2.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(7)));
        factorsList2.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(8.0f)));
        factorsList2.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(Rational("2.1r"))));
        std::list<SymbolType> symbols2;
        symbols2.push_back(MULTIPLY);
        symbols2.push_back(DIVIDE);
        SimpleExpression simpleExpression2(std::move(factorsList2),symbols2);

        std::list<std::unique_ptr<SimpleExpression>> simpleExpressions;
        std::list<SymbolType> addSymbols;
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpression)));
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpression2)));

        addSymbols.push_back(ADD);
        Expression expression(std::move(simpleExpressions),addSymbols);
        std::vector<std::shared_ptr<Node>> nodes;
        nodes.push_back(std::make_shared<Node>(8));
        Variable myVariable("myVariable",std::move(nodes),1);
        Assignment assignment(&myVariable,std::make_unique<Expression>(expression),0);
        assignment.execute();
        BOOST_CHECK_EQUAL(myVariable.isSingleNode(),true);
        BOOST_CHECK_EQUAL(myVariable.getName(),"myVariable");
        BOOST_CHECK_EQUAL(myVariable.getNode().getValue().floatVal,42.0f);
        BOOST_CHECK_EQUAL(myVariable.getNode().getTypeKind(),FLOAT);
}

    BOOST_AUTO_TEST_CASE(expression_with_subtracting_two_simpleexpressions){
        std::list<std::unique_ptr<Factor>> factorsList;
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(7)));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(8.0f)));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(Rational("4.1r"))));
        std::list<SymbolType> symbols;
        symbols.push_back(MULTIPLY);
        symbols.push_back(DIVIDE);
        SimpleExpression simpleExpression(std::move(factorsList),symbols);

        std::list<std::unique_ptr<Factor>> factorsList2;
        factorsList2.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(7)));
        factorsList2.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(8.0f)));
        factorsList2.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(Rational("2.1r"))));
        std::list<SymbolType> symbols2;
        symbols2.push_back(MULTIPLY);
        symbols2.push_back(DIVIDE);
        SimpleExpression simpleExpression2(std::move(factorsList2),symbols2);

        std::list<std::unique_ptr<SimpleExpression>> simpleExpressions;
        std::list<SymbolType> addSymbols;
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpression)));
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpression2)));

        addSymbols.push_back(SUBTRACT);
        Expression expression(std::move(simpleExpressions),addSymbols);
        std::vector<std::shared_ptr<Node>> nodes;
        nodes.push_back(std::make_shared<Node>(8));
        Variable myVariable("myVariable",std::move(nodes),1);
        Assignment assignment(&myVariable,std::make_unique<Expression>(expression),0);
        assignment.execute();
        BOOST_CHECK_EQUAL(myVariable.isSingleNode(),true);
        BOOST_CHECK_EQUAL(myVariable.getName(),"myVariable");
        BOOST_CHECK_EQUAL(myVariable.getNode().getValue().floatVal,-14.0f);
        BOOST_CHECK_EQUAL(myVariable.getNode().getTypeKind(),FLOAT);
}

    BOOST_AUTO_TEST_CASE(expression_with_equation_on_multiple_simple_expressions){
        std::list<std::unique_ptr<Factor>> factorsList;
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(7)));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(8.0f)));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(Rational("4.1r"))));
        std::list<SymbolType> symbols;
        symbols.push_back(MULTIPLY);
        symbols.push_back(DIVIDE);
        SimpleExpression simpleExpression(std::move(factorsList),symbols);

        std::list<std::unique_ptr<Factor>> factorsList2;
        factorsList2.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(7)));
        factorsList2.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(8.0f)));
        factorsList2.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(Rational("2.1r"))));
        std::list<SymbolType> symbols2;
        symbols2.push_back(MULTIPLY);
        symbols2.push_back(DIVIDE);
        SimpleExpression simpleExpression2(std::move(factorsList2),symbols2);

        std::list<std::unique_ptr<Factor>> factorsList3;
        factorsList3.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(7)));
        factorsList3.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(8.0f)));
        factorsList3.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(Rational("1.1r"))));
        std::list<SymbolType> symbols3;
        symbols3.push_back(MULTIPLY);
        symbols3.push_back(DIVIDE);
        SimpleExpression simpleExpression3(std::move(factorsList3),symbols3);

        std::list<std::unique_ptr<SimpleExpression>> simpleExpressions;
        std::list<SymbolType> addSymbols;
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpression)));
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpression2)));
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpression3)));

        addSymbols.push_back(ADD);
        addSymbols.push_back(SUBTRACT);
        Expression expression(std::move(simpleExpressions),addSymbols);
        std::vector<std::shared_ptr<Node>> nodes;
        nodes.push_back(std::make_shared<Node>(8));
        Variable myVariable("myVariable",std::move(nodes),1);
        Assignment assignment(&myVariable,std::make_unique<Expression>(expression),0);
        assignment.execute();
        BOOST_CHECK_EQUAL(myVariable.isSingleNode(),true);
        BOOST_CHECK_EQUAL(myVariable.getName(),"myVariable");
        BOOST_CHECK_EQUAL(myVariable.getNode().getValue().floatVal,-14.0f);
        BOOST_CHECK_EQUAL(myVariable.getNode().getTypeKind(),FLOAT);
}

    BOOST_AUTO_TEST_CASE(expression_with_equation_on_simplesexpression_one_of_which_conitains_expressionfactor){

        std::list<std::unique_ptr<Factor>> factorsList;
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(7)));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(8.0f)));
        factorsList.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(Rational("4.1r"))));
//------------EXPRESSION FACTOR---------------------------------------------------------------------///
        std::list<std::unique_ptr<Factor>> factorsListTemp;
        factorsListTemp.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(7)));
        std::list<SymbolType> symbolsTemp;
        std::list<std::unique_ptr<SimpleExpression>> simpleExpressionsTemp;
        std::list<SymbolType> addSymbolsTemp;
        SimpleExpression simpleExpressionTemp(std::move(factorsListTemp),symbolsTemp);
        simpleExpressionsTemp.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpressionTemp)));
        Expression expressionTemp(std::move(simpleExpressionsTemp),addSymbolsTemp);
        ExpressionFactor expressionFactor(std::make_unique<Expression>(expressionTemp));
        factorsList.push_back(std::make_unique<ExpressionFactor>(expressionFactor));


        std::list<SymbolType> symbols;
        symbols.push_back(MULTIPLY);
        symbols.push_back(DIVIDE);
        symbols.push_back(DIVIDE);
        SimpleExpression simpleExpression(std::move(factorsList),symbols);

        std::list<std::unique_ptr<Factor>> factorsList2;
        factorsList2.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(7)));
        factorsList2.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(8.0f)));
        factorsList2.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(Rational("2.1r"))));
        std::list<SymbolType> symbols2;
        symbols2.push_back(MULTIPLY);
        symbols2.push_back(DIVIDE);
        SimpleExpression simpleExpression2(std::move(factorsList2),symbols2);

        std::list<std::unique_ptr<Factor>> factorsList3;
        factorsList3.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(7)));
        factorsList3.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(8.0f)));
        factorsList3.push_back(std::make_unique<ValueFactor>(std::make_shared<Node>(Rational("1.1r"))));
        std::list<SymbolType> symbols3;
        symbols3.push_back(MULTIPLY);
        symbols3.push_back(DIVIDE);
        SimpleExpression simpleExpression3(std::move(factorsList3),symbols3);

        std::list<std::unique_ptr<SimpleExpression>> simpleExpressions;
        std::list<SymbolType> addSymbols;
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpression)));
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpression2)));
        simpleExpressions.push_back(std::make_unique<SimpleExpression>(std::move(simpleExpression3)));

        addSymbols.push_back(ADD);
        addSymbols.push_back(SUBTRACT);
        Expression expression(std::move(simpleExpressions),addSymbols);
        std::vector<std::shared_ptr<Node>> nodes;
        nodes.push_back(std::make_shared<Node>(8));
        Variable myVariable("myVariable",std::move(nodes),1);
        Assignment assignment(&myVariable,std::make_unique<Expression>(expression),0);
        assignment.execute();
        BOOST_CHECK_EQUAL(myVariable.isSingleNode(),true);
        BOOST_CHECK_EQUAL(myVariable.getName(),"myVariable");
        BOOST_CHECK_EQUAL(myVariable.getNode().getValue().floatVal,-26.0f);
        BOOST_CHECK_EQUAL(myVariable.getNode().getTypeKind(),FLOAT);
}

BOOST_AUTO_TEST_SUITE_END()