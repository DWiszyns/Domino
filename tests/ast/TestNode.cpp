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
        BOOST_CHECK_EQUAL(x, n.getValue().integer);
        BOOST_CHECK_EQUAL(n.getTypeKind(),INT);
    }

    BOOST_AUTO_TEST_CASE(node_from_rational){
        Rational x="7.5r";
        Node n(x);
        BOOST_CHECK_EQUAL(x.getRational(), n.getValue().rational.getRational());
        BOOST_CHECK_EQUAL(n.getTypeKind(),RATIONAL);
    }

    BOOST_AUTO_TEST_CASE(node_from_float){
        float x=7.7f;
        Node n(x);
        BOOST_CHECK_EQUAL(x, n.getValue().floatVal);
        BOOST_CHECK_EQUAL(n.getTypeKind(),FLOAT);
    }

    BOOST_AUTO_TEST_CASE(node_from_string){
        std::string x="asdsa";
        Node n(x);
        BOOST_CHECK_EQUAL(x,*(n.getValue().str));
        BOOST_CHECK_EQUAL(n.getTypeKind(),STRING);
    }

    BOOST_AUTO_TEST_CASE(node_from_char){
        char x='c';
        Node n(x);
        BOOST_CHECK_EQUAL(x, n.getValue().character);
        BOOST_CHECK_EQUAL(n.getTypeKind(),CHAR);
    }

    BOOST_AUTO_TEST_CASE(node_from_bool){
        bool x=true;
        Node n(x);
        BOOST_CHECK_EQUAL(x, n.getValue().boolean);
        BOOST_CHECK_EQUAL(n.getTypeKind(),BOOLEAN);
    }

    BOOST_AUTO_TEST_CASE(node_from_node){
        bool x=true;
        Node n(x);
        Node h(n);
        BOOST_CHECK_EQUAL(x, h.getValue().boolean);
        BOOST_CHECK_EQUAL(h.getTypeKind(),BOOLEAN);
    }

    BOOST_AUTO_TEST_CASE(node_from_value){
        Value x;
        x.boolean=true;
        TypeKind typekind=BOOLEAN;
        Node n(x,typekind);
        BOOST_CHECK_EQUAL(true, n.getValue().boolean);
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
        BOOST_CHECK_EQUAL(15, o.getValue().integer);
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
        BOOST_CHECK_EQUAL(15.0f, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(p.getValue().floatVal, o.getValue().floatVal);
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
        BOOST_CHECK_EQUAL(15.0f, o.getValue().floatVal);
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
        BOOST_CHECK_EQUAL(15.0f, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(p.getValue().floatVal, o.getValue().floatVal);
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
        BOOST_CHECK_EQUAL("15.1r", o.getValue().rational.getRational());
        BOOST_CHECK_EQUAL(o.getTypeKind(),RATIONAL);
    }

    BOOST_AUTO_TEST_CASE(adding_two_nodes_rational_and_int){
        BOOST_TEST_PASSPOINT();
        int x=7;
        Rational y("8.1r");
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m+n);
        Node p(n+m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL("15.1r", o.getValue().rational.getRational());
        BOOST_CHECK_EQUAL(p.getValue().rational.getRational(), o.getValue().rational.getRational());
        BOOST_CHECK_EQUAL(o.getTypeKind(),RATIONAL);
        BOOST_CHECK_EQUAL(p.getTypeKind(),RATIONAL);
    }

    BOOST_AUTO_TEST_CASE(subtracting_two_nodes_integers){
        BOOST_TEST_PASSPOINT();
        int x=7;
        int y=8;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(n-m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(1, o.getValue().integer);
        BOOST_CHECK_EQUAL(o.getTypeKind(),INT);
    }

    BOOST_AUTO_TEST_CASE(subtracting_two_nodes_float_and_integer){
        BOOST_TEST_PASSPOINT();
        int x=7;
        float y=8.0f;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m-n);
        Node p(n-m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(-1.0f, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(-1* p.getValue().floatVal, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(o.getTypeKind(),FLOAT);
        BOOST_CHECK_EQUAL(p.getTypeKind(),FLOAT);

    }

    BOOST_AUTO_TEST_CASE(subtracting_two_nodes_floats){
        BOOST_TEST_PASSPOINT();
        float x=7.0f;
        float y=8.0f;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m-n);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(-1.0f, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(o.getTypeKind(),FLOAT);
    }

    BOOST_AUTO_TEST_CASE(subtracting_two_nodes_rational_and_float){
        BOOST_TEST_PASSPOINT();
        Rational x("7.1r");
        float y=8.0f;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m-n);
        Node p(n-m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(-1.0f, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(-1* p.getValue().floatVal, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(o.getTypeKind(),FLOAT);
        BOOST_CHECK_EQUAL(p.getTypeKind(),FLOAT);
    }

    BOOST_AUTO_TEST_CASE(subtracting_two_nodes_rationals){
        BOOST_TEST_PASSPOINT();
        Rational x("7.1r");
        Rational y("8.1r");
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m-n);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL("-1.1r", o.getValue().rational.getRational());
        BOOST_CHECK_EQUAL(o.getTypeKind(),RATIONAL);
    }

    BOOST_AUTO_TEST_CASE(subtracting_two_nodes_rational_and_int){
        BOOST_TEST_PASSPOINT();
        int x=7;
        Rational y("8.1r");
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m-n);
        Node p(n-m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL("-1.1r", o.getValue().rational.getRational());
        BOOST_CHECK_EQUAL(p.getValue().rational.getRational(),"1.1r");
        BOOST_CHECK_EQUAL(o.getTypeKind(),RATIONAL);
        BOOST_CHECK_EQUAL(p.getTypeKind(),RATIONAL);
    }

    BOOST_AUTO_TEST_CASE(multiplying_two_nodes_integers){
        BOOST_TEST_PASSPOINT();
        int x=7;
        int y=8;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(n*m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(56, o.getValue().integer);
        BOOST_CHECK_EQUAL(o.getTypeKind(),INT);
    }

    BOOST_AUTO_TEST_CASE(multiplying_two_nodes_float_and_integer){
        BOOST_TEST_PASSPOINT();
        int x=7;
        float y=8.0f;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m*n);
        Node p(n*m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(56.0f, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(p.getValue().floatVal, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(o.getTypeKind(),FLOAT);
        BOOST_CHECK_EQUAL(p.getTypeKind(),FLOAT);

    }

    BOOST_AUTO_TEST_CASE(multiplying_two_nodes_floats){
        BOOST_TEST_PASSPOINT();
        float x=7.0f;
        float y=8.0f;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m*n);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(56.0f, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(o.getTypeKind(),FLOAT);
    }

    BOOST_AUTO_TEST_CASE(multiplying_two_nodes_rational_and_float){
        BOOST_TEST_PASSPOINT();
        Rational x("7.1r");
        float y=8.0f;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m*n);
        Node p(n*m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(56.0f, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(p.getValue().floatVal, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(o.getTypeKind(),FLOAT);
        BOOST_CHECK_EQUAL(p.getTypeKind(),FLOAT);
    }

    BOOST_AUTO_TEST_CASE(multiplying_two_nodes_rationals){
        BOOST_TEST_PASSPOINT();
        Rational x("7.1r");
        Rational y("8.1r");
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m*n);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL("56.1r", o.getValue().rational.getRational());
        BOOST_CHECK_EQUAL(o.getTypeKind(),RATIONAL);
    }

    BOOST_AUTO_TEST_CASE(multilying_two_nodes_rational_and_int){
        BOOST_TEST_PASSPOINT();
        int x=7;
        Rational y("8.1r");
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m*n);
        Node p(n*m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL("56.1r", o.getValue().rational.getRational());
        BOOST_CHECK_EQUAL(p.getValue().rational.getRational(),"56.1r");
        BOOST_CHECK_EQUAL(o.getTypeKind(),RATIONAL);
        BOOST_CHECK_EQUAL(p.getTypeKind(),RATIONAL);
    }

    BOOST_AUTO_TEST_CASE(dividing_two_nodes_integers){
        BOOST_TEST_PASSPOINT();
        int x=7;
        int y=14;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(n/m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(2, o.getValue().integer);
        BOOST_CHECK_EQUAL(o.getTypeKind(),INT);
    }

    BOOST_AUTO_TEST_CASE(dividing_two_nodes_float_and_integer){
        BOOST_TEST_PASSPOINT();
        int x=7;
        float y=14.0f;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m/n);
        Node p(n/m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(0.5f, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(1/ p.getValue().floatVal, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(o.getTypeKind(),FLOAT);
        BOOST_CHECK_EQUAL(p.getTypeKind(),FLOAT);

    }

    BOOST_AUTO_TEST_CASE(dividing_two_nodes_floats){
        BOOST_TEST_PASSPOINT();
        float x=7.0f;
        float y=14.0f;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(n/m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(2.0f, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(o.getTypeKind(),FLOAT);
    }

    BOOST_AUTO_TEST_CASE(dividing_two_nodes_rational_and_float){
        BOOST_TEST_PASSPOINT();
        Rational x("7.1r");
        float y=14.0f;
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m/n);
        Node p(n/m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL(0.5f, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(1/ p.getValue().floatVal, o.getValue().floatVal);
        BOOST_CHECK_EQUAL(o.getTypeKind(),FLOAT);
        BOOST_CHECK_EQUAL(p.getTypeKind(),FLOAT);
    }

    BOOST_AUTO_TEST_CASE(dividing_two_nodes_rationals){
        BOOST_TEST_PASSPOINT();
        Rational x("7.1r");
        Rational y("8.1r");
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m*n);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL("56.1r", o.getValue().rational.getRational());
        BOOST_CHECK_EQUAL(o.getTypeKind(),RATIONAL);
    }

    BOOST_AUTO_TEST_CASE(dividing_two_nodes_rational_and_int){
        BOOST_TEST_PASSPOINT();
        int x=7;
        Rational y("14.1r");
        BOOST_TEST_PASSPOINT();
        Node m(x);
        Node n(y);
        Node o(m/n);
        Node p(n/m);
        BOOST_TEST_PASSPOINT();
        BOOST_CHECK_EQUAL("1.2r", o.getValue().rational.getRational());
        BOOST_CHECK_EQUAL(p.getValue().rational.getRational(),"2.1r");
        BOOST_CHECK_EQUAL(o.getTypeKind(),RATIONAL);
        BOOST_CHECK_EQUAL(p.getTypeKind(),RATIONAL);
    }


BOOST_AUTO_TEST_SUITE_END()