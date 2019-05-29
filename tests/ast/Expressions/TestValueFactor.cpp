//
// Created by dominik on 5/27/19.
//

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <ast/Variable.h>
#include "ast/Factor/ValueFactor.h"

BOOST_AUTO_TEST_SUITE(ValueFactorTest)

    BOOST_AUTO_TEST_CASE(factor_from_value){
        int x=7;
        Node n(x);
        ValueFactor myFactor(n);
        BOOST_CHECK_EQUAL(myFactor.calculate().getNewValue().integer,7);
        BOOST_CHECK_EQUAL(myFactor.calculate().getTypeKind(),INT);
    }

    BOOST_AUTO_TEST_CASE(factor_from_variable){
        float x=7.0f;
        Node n(x);
        Node m(8.0f);
        std::vector<std::unique_ptr<Node>> nodes;
        nodes.push_back(std::make_unique<Node>(n));
        nodes.push_back(std::make_unique<Node>(m));
        Variable myVariable("myVariable",std::move(nodes),2);
        ValueFactor myFactor(myVariable.getNodeByIndex(1));
        BOOST_CHECK_EQUAL(myFactor.calculate().getNewValue().floatVal,8.0f);
        BOOST_CHECK_EQUAL(myFactor.calculate().getTypeKind(),FLOAT);
    }

BOOST_AUTO_TEST_SUITE_END()