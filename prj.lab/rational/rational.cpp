
#include "rational/rational.hpp"
#include <iostream>
#include <stdexcept>

Rational::Rational(const std::int32_t num, const std::int32_t den)
    : num_(num), den_(den) {
    if (0 == den_) {
        throw std::invaliden_argument("Zero denumenator in Rational ctor");
    }
    if (den_ < 0) {
        num_ = -num_;
        den_ = -den_;
    }
    gcd();
}

Rational& Rational::gcd() {
    int32_t a = abs(num_), b = abs(den_);
    if (a < b) {
        std::swap(a, b);
    }
    if (b == 0) {
        num_ = 0, den_ = 1;
        return *this;
    };
    while (a % b != 0) {
        a %= b;
        std::swap(a, b);
    }
    num_ /= b;
    den_ /= b;
    return *this;
}




bool Rational::operator<(const Rational& rhs) const noexcept {
    return (num_ * rhs.den_ < rhs.num_ * den_);
}
bool Rational::operator<=(const Rational& rhs) const noexcept {
    return (num_ * rhs.den_ <= rhs.num_ * den_);
}
bool Rational::operator>(const Rational& rhs) const noexcept {
    return (num_ * rhs.den_ > rhs.num_ * den_);
}
bool Rational::operator>=(const Rational& rhs) const noexcept {
    return (num_ * rhs.den_ >= rhs.num_ * den_);
}


Rational& Rational::operator+=(const Rational& rhs) noexcept
{
    num_ *= rhs.den_;
    num_ += rhs.num_ * den_;
    den_ *= rhs.den_;
    return gcd();
};
Rational& Rational::operator-=(const Rational& rhs) noexcept 
{
    num_ *= rhs.den_;
    num_ -= rhs.num_ * den_;
    den_ *= rhs.den_;
    return gcd();
};
Rational& Rational::operator*=(const Rational& rhs) noexcept 
{
    num_ *= rhs.num_;
    den_ *= rhs.den_;
    return gcd();
};
Rational& Rational::operator/=(const Rational& rhs) 
{
    if (rhs.num_ == 0) {
        throw std::runtime_error("Division by zero");
    }
    num_ *= rhs.den_;
    den_ *= rhs.num_;
    return gcd();
};

Rational& Rational::operator+=(const int32_t rhs) noexcept 
{
    Rational tmp{ rhs };
    *this += tmp;
    return *this;
};
Rational& Rational::operator-=(const int32_t rhs) noexcept 
{
    Rational tmp{ rhs };
    *this -= tmp;
    return *this;
};
Rational& Rational::operator*=(const int32_t rhs) noexcept 
{
    Rational tmp{ rhs };
    *this *= tmp;
    return *this;
};
Rational& Rational::operator/=(const int32_t rhs) 
{
    Rational tmp{ rhs };
    return *this /= tmp;
};


Rational operator+(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } -= rhs; }
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } *= rhs; }
Rational operator/(const Rational& lhs, const Rational& rhs) { return Rational{ lhs } /= rhs; }
Rational operator+(const Rational& lhs, const int32_t rhs) noexcept { return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const int32_t rhs) noexcept { return Rational{ lhs } -= rhs; };
Rational operator*(const Rational& lhs, const int32_t rhs) noexcept { return Rational{ lhs } *= rhs; };
Rational operator/(const Rational& lhs, const int32_t rhs) { return Rational{ lhs } /= rhs; }
Rational operator+(const int32_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator-(const int32_t lhs, const Rational& rhs) noexcept { return operator-(rhs, lhs); }
Rational operator*(const int32_t lhs, const Rational& rhs) noexcept { return operator*(rhs, lhs); }
Rational operator/(const int32_t lhs, const Rational& rhs) { return operator/(rhs, lhs); }


std::ostream& Rational::WriteTo(std::ostream& ostrm) const noexcept {
    ostrm << num_ << separator << den_;
    return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) noexcept {
    int32_t num = 0;
    int32_t den = 1;
    char sep = '0';
    istrm >> num;
    istrm.get(sep);
    int32_t tr = istrm.peek();
    istrm >> den;
    if (!istrm || tr > '9' || tr < '0') {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }if (istrm.good() || istrm.eof()) {
        if ('/' == sep && den > 0) {
            *this = Rational(num, den);
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}
