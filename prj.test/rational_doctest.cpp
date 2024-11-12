#include <rational/rational.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[rational] - ctor") {
  CHECK(Rational() == Rational(0.0, 0.0));
  CHECK(Rational(4.0) == Rational(4.0, 0.0));
}
