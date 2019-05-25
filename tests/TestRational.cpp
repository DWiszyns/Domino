//
// Created by dominik on 5/25/19.
//

#include <iostream>
#include "Rational.h"
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(RationalTest)

    BOOST_AUTO_TEST_CASE(rational_from_string){
        Rational r("1.5r");
        BOOST_CHECK_EQUAL( r.getDenominator(), 5 );
        BOOST_CHECK_EQUAL( r.getNumerator(), 1 );
        BOOST_CHECK_EQUAL(r.getRational(),"1.5r");
    }

    BOOST_AUTO_TEST_CASE(rational_from_numbers){
        Rational r(1,5);
        BOOST_CHECK_EQUAL( r.getDenominator(), 5 );
        BOOST_CHECK_EQUAL( r.getNumerator(), 1 );
        BOOST_CHECK_EQUAL(r.getRational(),"1.5r");
    }

    BOOST_AUTO_TEST_CASE(creating_rational_from_other_rational){
        Rational r(Rational("1.5r"));
        Rational x=r;
        BOOST_CHECK_EQUAL( x.getDenominator(), 5 );
        BOOST_CHECK_EQUAL( x.getNumerator(), 1 );
        BOOST_CHECK_EQUAL(x.getRational(),"1.5r");
    }

    BOOST_AUTO_TEST_CASE(assigning_rationals){
        Rational r(1,5);
        Rational x=r;
        BOOST_CHECK_EQUAL( x.getDenominator(), 5 );
        BOOST_CHECK_EQUAL( x.getNumerator(), 1 );
        BOOST_CHECK_EQUAL(x.getRational(),"1.5r");
    }

    BOOST_AUTO_TEST_CASE(adding_rationals){
        Rational r(1,5);
        Rational z("1.5r");
        Rational x=r+z;
        BOOST_CHECK_EQUAL( x.getDenominator(), 5 );
        BOOST_CHECK_EQUAL( x.getNumerator(), 2 );
        BOOST_CHECK_EQUAL(x.getRational(),"2.5r");
    }

    BOOST_AUTO_TEST_CASE(subtracting_rationals){
        Rational r(1,5);
        Rational z("1.5r");
        Rational x=r-z;
        BOOST_CHECK_EQUAL( x.getDenominator(), 1 );
        BOOST_CHECK_EQUAL( x.getNumerator(), 0 );
        BOOST_CHECK_EQUAL(x.getRational(),"0.1r");
    }

    BOOST_AUTO_TEST_CASE(multiplying_rationals){
        Rational r(1,5);
        Rational z("1.5r");
        Rational x=r*z;
        BOOST_CHECK_EQUAL( x.getDenominator(), 25 );
        BOOST_CHECK_EQUAL( x.getNumerator(), 1);
        BOOST_CHECK_EQUAL(x.getRational(),"1.25r");
    }

    BOOST_AUTO_TEST_CASE(dividing_rationals){
        Rational r(1,5);
        Rational z("1.5r");
        Rational x=r/z;
        BOOST_CHECK_EQUAL( x.getDenominator(), 1 );
        BOOST_CHECK_EQUAL( x.getNumerator(), 1);
        BOOST_CHECK_EQUAL(x.getRational(),"1.1r");
    }

    BOOST_AUTO_TEST_CASE(adding_rationals_straight_to_variable){
        Rational x(1,5);
        Rational z("1.5r");
        x+=z;
        BOOST_CHECK_EQUAL( x.getDenominator(), 5 );
        BOOST_CHECK_EQUAL( x.getNumerator(), 2 );
        BOOST_CHECK_EQUAL(x.getRational(),"2.5r");
    }

    BOOST_AUTO_TEST_CASE(subtracting_rationals_straight_to_variable){
        Rational x(1,5);
        Rational z("1.5r");
        x-=z;
        BOOST_CHECK_EQUAL( x.getDenominator(), 1 );
        BOOST_CHECK_EQUAL( x.getNumerator(), 0 );
        BOOST_CHECK_EQUAL(x.getRational(),"0.1r");
    }

    BOOST_AUTO_TEST_CASE(multiplying_rationals_straight_to_variable){
        Rational x(1,5);
        Rational z("1.5r");
        x*=z;
        BOOST_CHECK_EQUAL( x.getDenominator(), 25 );
        BOOST_CHECK_EQUAL( x.getNumerator(), 1);
        BOOST_CHECK_EQUAL(x.getRational(),"1.25r");
    }

    BOOST_AUTO_TEST_CASE(dividing_rationals_straight_to_variable){
        Rational x(1,5);
        Rational z("1.5r");
        x/=z;
        BOOST_CHECK_EQUAL( x.getDenominator(), 1 );
        BOOST_CHECK_EQUAL( x.getNumerator(), 1);
        BOOST_CHECK_EQUAL(x.getRational(),"1.1r");
    }

    BOOST_AUTO_TEST_CASE(check_equal_true){
        Rational x(1,5);
        Rational z("1.5r");
        BOOST_CHECK_EQUAL(x==z,true);
    }

    BOOST_AUTO_TEST_CASE(check_equal_false){
        Rational x(1,5);
        Rational z("1.4r");
        BOOST_CHECK_EQUAL(x==z,false);
    }

    BOOST_AUTO_TEST_CASE(check_different_true){
        Rational x(1,5);
        Rational z("1.4r");
        BOOST_CHECK_EQUAL(x!=z,true);
    }

    BOOST_AUTO_TEST_CASE(check_different_false){
        Rational x(1,5);
        Rational z("1.5r");
        BOOST_CHECK_EQUAL(x!=z,false);
    }

    BOOST_AUTO_TEST_CASE(check_greater_true){
        Rational x(1,4);
        Rational z("1.5r");
        BOOST_CHECK_EQUAL(x>z,true);
    }

    BOOST_AUTO_TEST_CASE(check_greater_false){
        Rational x(1,5);
        Rational z("1.5r");
        BOOST_CHECK_EQUAL(x>z,false);
    }

    BOOST_AUTO_TEST_CASE(check_less_true){
        Rational x(1,5);
        Rational z("1.4r");
        BOOST_CHECK_EQUAL(x<z,true);
    }

    BOOST_AUTO_TEST_CASE(check_less_false){
        Rational x(1,5);
        Rational z("1.5r");
        BOOST_CHECK_EQUAL(x<z,false);
    }

    BOOST_AUTO_TEST_CASE(check_greater_or_equal_true_greater){
        Rational x(1,4);
        Rational z("1.5r");
        BOOST_CHECK_EQUAL(x>=z,true);
    }

    BOOST_AUTO_TEST_CASE(check_greater_or_equal_true_equal){
        Rational x(1,5);
        Rational z("2.10r");
        BOOST_CHECK_EQUAL(x>=z,true);
    }

    BOOST_AUTO_TEST_CASE(check_greater_or_equal_false){
        Rational x(1,6);
        Rational z("1.5r");
        BOOST_CHECK_EQUAL(x>=z,false);
    }

    BOOST_AUTO_TEST_CASE(check_less_or_equal_true_less){
        Rational x(1,5);
        Rational z("1.4r");
        BOOST_CHECK_EQUAL(x<=z,true);
    }

    BOOST_AUTO_TEST_CASE(check_less_or_equal_true_equal){
        Rational x(1,5);
        Rational z("1.5r");
        BOOST_CHECK_EQUAL(x<=z,true);
    }

    BOOST_AUTO_TEST_CASE(check_less_or_equal_false){
        Rational x(1,4);
        Rational z("1.5r");
        BOOST_CHECK_EQUAL(x<=z,false);
    }

    BOOST_AUTO_TEST_CASE(array){
        Rational x[5];
        x[0]="1.5r";
        x[1]="1.2r";
        BOOST_CHECK_EQUAL(x[0].getDenominator(),5);
    }

BOOST_AUTO_TEST_SUITE_END()