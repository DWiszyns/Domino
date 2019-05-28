//
// Created by dominik on 5/27/19.
//

#include <iostream>
#include "ast/Node/Node.h"
#include <boost/test/unit_test.hpp>
#include "ast/Node/ValueTypeVisitor.h"
#include "ast/Node/Visitors/visitors.h"

BOOST_AUTO_TEST_SUITE(NodeTest)

    BOOST_AUTO_TEST_CASE(node_from_int){
        BOOST_TEST_PASSPOINT();
        int x=7;
        BOOST_TEST_PASSPOINT();
        Node n(x);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(x,n.getNewValue().integer);
        BOOST_CHECK_EQUAL(n.getTypeKind(),INT);
        //std::cout<<n<<std::endl;
        //if(type==INT) int z =(int) boost::apply_visitor(IntTypeVisitor(),y);
        //if(x == n.getValue())n std::cout << n.getValue();
        //BOOST_CHECK_EQUAL( n.getValue(), x );
       // BOOST_CHECK_EQUAL(type,BOOLEAN);
    }

    BOOST_AUTO_TEST_CASE(node_from_rational){
            BOOST_TEST_PASSPOINT();
            Rational x="7.5r";
            BOOST_TEST_PASSPOINT();
            Node n(x);
            BOOST_TEST_PASSPOINT();
            BOOST_CHECK_EQUAL(x.getRational(),n.getNewValue().rational->getRational());
            BOOST_CHECK_EQUAL(n.getTypeKind(),RATIONAL);
    }

    BOOST_AUTO_TEST_CASE(node_from_float){
            BOOST_TEST_PASSPOINT();
            float x=7.7f;
            BOOST_TEST_PASSPOINT();
            Node n(x);
            BOOST_TEST_PASSPOINT();
            BOOST_CHECK_EQUAL(x,n.getNewValue().floatVal);
            BOOST_CHECK_EQUAL(n.getTypeKind(),FLOAT);
    }

    BOOST_AUTO_TEST_CASE(node_from_string){
        BOOST_TEST_PASSPOINT();
        std::string x="asdsa";
        BOOST_TEST_PASSPOINT();
        Node n(x);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(x,*(n.getNewValue().str));
        BOOST_CHECK_EQUAL(n.getTypeKind(),STRING);
    }

BOOST_AUTO_TEST_SUITE_END()