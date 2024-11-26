#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <complex/complex.hpp>

TEST_CASE("[complex] - ctor") {
  CHECK(Complex() == Complex(0.0, 0.0));
  CHECK(Complex(2.0) == Complex(2.0, 0.0));
}

TEST_CASE("Operations with complex numbers") {
  CHECK(Complex(4, 2) / Complex(-1, 1) == Complex(-1, -3));
  CHECK(Complex(4, 5) / Complex(0, 2) == Complex(2.5, -2));

  CHECK(Complex(3, 1) + Complex(5, -2) == Complex(8, -1));
  CHECK(Complex(5, -6) + Complex(-3, 2) == Complex(2, -4));

  CHECK(Complex(3, 1) - Complex(5, -2) == Complex(-2, 3));
  CHECK(Complex(5, -6) - Complex(-3, 2) == Complex(8, -8));

  CHECK(Complex(1, 4) * Complex(3, 5) == Complex(-17, 17));
  CHECK(Complex(5, 0) * Complex(4, 7) == Complex(20, 35));
}

TEST_CASE("Ostream") {
  Complex a, b;
  std::ostringstream os;
  os << a;
  CHECK((os.str() == "{0,0}"));

}

TEST_CASE("Istream") {
  Complex a, b;
  std::istringstream is("{0,7}");
  is >> b;
  CHECK((b == Complex(0, 7)));
  

}
