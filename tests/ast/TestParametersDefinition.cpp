//
// Created by dominik on 5/30/19.
//

#include <boost/test/unit_test.hpp>
#include <iostream>
#include "ast/ParametersDefinition.h"

BOOST_AUTO_TEST_SUITE(ParametersDefinitionTest)

BOOST_AUTO_TEST_CASE(variable_from_int){
        Variable myVariable("myVariable",1,INT);
        std::vector<Variable> parameters;
        parameters.push_back(myVariable);
        ParametersDefinition paramsDef(parameters);
        BOOST_CHECK_EQUAL(paramsDef.getParameterType(0),INT);
        BOOST_CHECK_EQUAL(paramsDef.getParameter(0).getNode().getValue().integer,myVariable.getNode().getValue().integer);
    }

BOOST_AUTO_TEST_CASE(multipleparameters){
        Variable myVariable("myVariable",1,FLOAT);
        Variable myVariable2("myVariable",1,INT);
        std::vector<Variable> parameters;
        parameters.push_back(myVariable);
        parameters.push_back(myVariable2);
        ParametersDefinition paramsDef(parameters);
        BOOST_CHECK_EQUAL(paramsDef.getParameterType(0),FLOAT);
        BOOST_CHECK_EQUAL(paramsDef.getParameter(0).getNode().getValue().floatVal,myVariable.getNode().getValue().floatVal);
        BOOST_CHECK_EQUAL(paramsDef.getParameterType(1),INT);
        BOOST_CHECK_EQUAL(paramsDef.getParameter(1).getNode().getValue().integer,myVariable2.getNode().getValue().integer);
}

//TODO zabezpieczyc przed roznymi typami w tablicy

BOOST_AUTO_TEST_SUITE_END()
