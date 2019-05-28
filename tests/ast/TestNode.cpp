//
// Created by dominik on 5/27/19.
//

#include <iostream>
#include "ast/Node/Node.h"
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(NodeTest)

    BOOST_AUTO_TEST_CASE(node_from_int){
        int x=7;
        Node n(x);
        BOOST_CHECK_EQUAL(x,n.getNewValue().integer);
        BOOST_CHECK_EQUAL(n.getTypeKind(),INT);
    }

    BOOST_AUTO_TEST_CASE(node_from_rational){
        Rational x="7.5r";
        Node n(x);
        BOOST_CHECK_EQUAL(x.getRational(),n.getNewValue().rational->getRational());
        BOOST_CHECK_EQUAL(n.getTypeKind(),RATIONAL);
    }

    BOOST_AUTO_TEST_CASE(node_from_float){
        float x=7.7f;
        Node n(x);
        BOOST_CHECK_EQUAL(x,n.getNewValue().floatVal);
        BOOST_CHECK_EQUAL(n.getTypeKind(),FLOAT);
    }

    BOOST_AUTO_TEST_CASE(node_from_string){
        std::string x="asdsa";
        Node n(x);
        BOOST_CHECK_EQUAL(x,*(n.getNewValue().str));
        BOOST_CHECK_EQUAL(n.getTypeKind(),STRING);
    }

    BOOST_AUTO_TEST_CASE(node_from_char){
        char x='c';
        Node n(x);
        BOOST_CHECK_EQUAL(x,n.getNewValue().character);
        BOOST_CHECK_EQUAL(n.getTypeKind(),CHAR);
    }

    BOOST_AUTO_TEST_CASE(node_from_bool){
        bool x=true;
        Node n(x);
        BOOST_CHECK_EQUAL(x,n.getNewValue().boolean);
        BOOST_CHECK_EQUAL(n.getTypeKind(),BOOLEAN);
    }

    BOOST_AUTO_TEST_CASE(node_from_node){
        bool x=true;
        Node n(x);
        Node h(n);
        BOOST_CHECK_EQUAL(x,h.getNewValue().boolean);
        BOOST_CHECK_EQUAL(h.getTypeKind(),BOOLEAN);
    }

    BOOST_AUTO_TEST_CASE(node_from_value){
        Value x;
        x.boolean=true;
        TypeKind typekind=BOOLEAN;
        Node n(x,typekind);
        BOOST_CHECK_EQUAL(true,n.getNewValue().boolean);
        BOOST_CHECK_EQUAL(n.getTypeKind(),BOOLEAN);
    }

    BOOST_AUTO_TEST_CASE(adding_two_nodes_integers){
        BOOST_TEST_PASSPOINT();
        int x=7;
        int y=8;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m+n);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(15,o.getNewValue().integer);
        BOOST_CHECK_EQUAL(o.getTypeKind(),INT);
    }

    BOOST_AUTO_TEST_CASE(adding_two_nodes_float_and_integer){
        BOOST_TEST_PASSPOINT();
        int x=7;
        float y=8.0f;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m+n);
        Node p(n+m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(15.0f,o.getNewValue().floatVal);
        BOOST_CHECK_EQUAL(p.getNewValue().floatVal,o.getNewValue().floatVal);
        BOOST_CHECK_EQUAL(o.getTypeKind(),FLOAT);
        BOOST_CHECK_EQUAL(p.getTypeKind(),FLOAT);

    }

    BOOST_AUTO_TEST_CASE(adding_two_nodes_floats){
        BOOST_TEST_PASSPOINT();
        float x=7.0f;
        float y=8.0f;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m+n);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(15.0f,o.getNewValue().floatVal);
        BOOST_CHECK_EQUAL(o.getTypeKind(),FLOAT);
    }

    BOOST_AUTO_TEST_CASE(adding_two_nodes_rational_and_float){
        BOOST_TEST_PASSPOINT();
        Rational x("7.1r");
        float y=8.0f;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m+n);
        Node p(n+m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(15.0f,o.getNewValue().floatVal);
        BOOST_CHECK_EQUAL(p.getNewValue().floatVal,o.getNewValue().floatVal);
        BOOST_CHECK_EQUAL(o.getTypeKind(),FLOAT);
        BOOST_CHECK_EQUAL(p.getTypeKind(),FLOAT);
    }

    BOOST_AUTO_TEST_CASE(adding_two_nodes_rationals){
        BOOST_TEST_PASSPOINT();
        Rational x("7.1r");
        Rational y("8.1r");
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m+n);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL("15.1r",o.getNewValue().rational->getRational());
        BOOST_CHECK_EQUAL(o.getTypeKind(),RATIONAL);

    }


BOOST_AUTO_TEST_SUITE_END()