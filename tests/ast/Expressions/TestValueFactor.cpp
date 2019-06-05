//
// Created by dominik on 5/27/19.
//

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <ast/Node/Variable.h>
#include "ast/Expression/Factor/ValueFactor.h"

BOOST_AUTO_TEST_SUITE(ValueFactorTest)

    BOOST_AUTO_TEST_CASE(factor_from_value){
        int x=7;
        ValueFactor myFactor(std::make_shared<Node>(x));
        BOOST_CHECK_EQUAL(myFactor.calculate().getValue().integer,7);
        BOOST_CHECK_EQUAL(myFactor.calculate().getTypeKind(),INT);
    }

    BOOST_AUTO_TEST_CASE(factor_from_variable){
        float x=7.0f;
        Node n(x);
        Node m(8.0f);
        std::vector<std::shared_ptr<Node>> nodes;
        nodes.push_back(std::make_shared<Node>(n));
        nodes.push_back(std::make_shared<Node>(m));
        Variable myVariable("myVariable",std::move(nodes),2);
        ValueFactor myFactor(std::make_shared<Node>(myVariable.getNodeByIndex(1)));
        BOOST_CHECK_EQUAL(myFactor.calculate().getValue().floatVal,8.0f);
        BOOST_CHECK_EQUAL(myFactor.calculate().getTypeKind(),FLOAT);
    }

BOOST_AUTO_TEST_SUITE_END()