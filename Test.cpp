#include <iostream>
#include "doctest.h"
#include <stdexcept>
#include <sstream>
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Testing arithmetic operators")
{
    Fraction num1(1, 2);
    Fraction num2(1, 3);

    Fraction result = num1 + num2;
    CHECK(result == Fraction(5, 6));

    result = num1 - num2;
    CHECK(result == Fraction(1, 6));

    result = num1 * num2;
    CHECK(result == Fraction(1, 6));

    result = num1 / num2;
    CHECK(result == Fraction(3, 2));
}

TEST_CASE("Testing comparison operators")
{
    Fraction f1(1, 2);
    Fraction f2(1, 3);

    CHECK(f1 > f2);
    CHECK(f1 >= f2);
    CHECK(f2 < f1);
    CHECK(f2 <= f1);
    CHECK(f1 != f2);
    CHECK(f1 == Fraction(1, 2));
}

TEST_CASE("Testing increment/decrement operators")
{
    Fraction f1(1, 2);
    Fraction f2(2, 1);

    CHECK((++f1) == Fraction(3, 2));
    CHECK((--f1) == Fraction(1, 2));
    CHECK((f1++) == Fraction(1, 2));
    CHECK(f1 == Fraction(3, 2));
    CHECK((f2--) == Fraction(2, 1));
    CHECK(f2 == Fraction(1, 1));
}


TEST_CASE("Testing arithmetic operators with floats")
{
    Fraction f1(1, 2);
    float f2 = 0.3;

    Fraction f3 = f1 + f2;
    CHECK(f3 == Fraction(4, 5));

    f3 = f1 - f2;
    CHECK(f3 == Fraction(2, 10));

    f3 = f1 * f2;
    CHECK(f3 == Fraction(3, 20));

    f3 = f1 / f2;
    CHECK(f3 == Fraction(5, 3));
}


TEST_CASE("Create Fraction") {
    Fraction f1(1, 2);
    Fraction f2(2, 4);
    Fraction f3(-3, 4);
    Fraction f4(1, -2);
    Fraction f5(-2, -4);

    CHECK(f1.getNumerator () == 1);
    CHECK(f1.getDenominator() == 2);
    CHECK(f2.getNumerator () == 1);
    CHECK(f2.getDenominator()== 2);
    CHECK(f3.getNumerator () == -3);
    CHECK(f3.getDenominator() == 4);
    CHECK(f4.getNumerator () == -1);
    CHECK(f4.getDenominator() == 2);
    CHECK(f5.getNumerator () == 1);
    CHECK(f5.getDenominator() == 2);
}


TEST_CASE("Addition") {
    Fraction f1(1, 2);
    Fraction f2(1, 4);
    Fraction f3 = f1 + f2;
    Fraction f4 = f1 + 2;
   

    CHECK(f3.getNumerator () == 3);
    CHECK(f3.getDenominator() == 4);
    CHECK(f4.getNumerator () == 5);
    CHECK(f4.getDenominator() == 2);
   
}

TEST_CASE("Subtraction") {
    Fraction f1(1, 2);
    Fraction f2(1, 4);
    Fraction f3 = f1 - f2;
    Fraction f4 = f1 - 2;
   

    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 4);
    CHECK(f4.getNumerator() == -3);
    CHECK(f4.getDenominator() == 2);
  
}

TEST_CASE("Division by zero throws exception") {
    CHECK_THROWS_AS(Fraction(3, 0), std::invalid_argument);
}