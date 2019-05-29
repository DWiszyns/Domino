//
// Created by dominik on 5/27/19.
//

#include <boost/test/unit_test.hpp>
#include <iostream>
#include "ast/Variable.h"

BOOST_AUTO_TEST_SUITE(VariableTest)

    BOOST_AUTO_TEST_CASE(variable_from_int){
        int x=7;
        Node n(x);
        std::vector<std::unique_ptr<Node>> nodes;
        nodes.push_back(std::make_unique<Node>(n));
        Variable myVariable("myVariable",std::move(nodes),1);
        BOOST_CHECK_EQUAL(myVariable.isSingleNode(),true);
        BOOST_CHECK_EQUAL(myVariable.getName(),"myVariable");
        BOOST_CHECK_EQUAL(myVariable.getNode().getNewValue().integer,7);
        BOOST_CHECK_EQUAL(myVariable.getNode().getTypeKind(),INT);
    }

    BOOST_AUTO_TEST_CASE(array_from_ints){
            int x=7;
            Node n(x);
            Node m(8);
            std::vector<std::unique_ptr<Node>> nodes;
            nodes.push_back(std::make_unique<Node>(n));
            nodes.push_back(std::make_unique<Node>(m));
            Variable myVariable("myVariable",std::move(nodes),2);
            BOOST_CHECK_EQUAL(myVariable.isSingleNode(),false);
            BOOST_CHECK_EQUAL(myVariable.getName(),"myVariable");
            BOOST_CHECK_EQUAL(myVariable.getNodeByIndex(1).getNewValue().integer,8);
            BOOST_CHECK_EQUAL(myVariable.getNode().getTypeKind(),INT);
    }

    //TODO zabezpieczyc przed roznymi typami w tablicy

BOOST_AUTO_TEST_SUITE_END()

