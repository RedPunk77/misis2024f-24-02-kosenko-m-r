
#pragma once
#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <cstdint>
#include <iosfwd>
#include <stdexcept>

class Rational {
public:
	Rational() = default;
	Rational(const Rational&) = default;
	explicit Rational(const std::int32_t num) noexcept : num_(num) { }
	Rational(const std::int32_t num, const std::int32_t den);
	~Rational() = default;
	Rational& operator=(const Rational&) = default;

	[[nodiscard]] std::int32_t num() const noexcept { return num_; }
	[[nodiscard]] std::int32_t den() const noexcept { return den_; }
	[[nodiscard]] bool operator==(const Rational& lhs) const noexcept { return (num_ * lhs.den_ == den_ * lhs.num_); }
	[[nodiscard]] bool operator!=(const Rational& lhs) const noexcept { return !operator==(lhs); }
	[[nodiscard]] bool operator<(const Rational& rhs) const noexcept;
	[[nodiscard]] bool operator<=(const Rational& rhs) const noexcept;
	[[nodiscard]] bool operator>(const Rational& rhs) const noexcept;
	[[nodiscard]] bool operator>=(const Rational& rhs) const noexcept;
	[[nodiscard]] Rational operator-() const noexcept { return { -num_, den_ }; }

	Rational& operator+=(const Rational& rhs) noexcept;
	Rational& operator-=(const Rational& rhs) noexcept;
	Rational& operator*=(const Rational& rhs) noexcept;
	Rational& operator/=(const Rational& rhs);

	Rational& operator+=(const int32_t rhs) noexcept;
	Rational& operator-=(const int32_t rhs) noexcept;
	Rational& operator*=(const int32_t rhs) noexcept;
	Rational& operator/=(const int32_t rhs);


	std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
	std::istream& ReadFrom(std::istream& istrm) noexcept;

	static const char separator{ '/' };

private:
	std::int32_t num_ = 0;
	std::int32_t den_ = 1;

	Rational& gcd();
};

[[nodiscard]] Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs);
[[nodiscard]] Rational operator+(const Rational& lhs, const int32_t rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const int32_t rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const int32_t rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const int32_t rhs);
[[nodiscard]] Rational operator+(const int32_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const int32_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const int32_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const int32_t lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& Rational) noexcept {
	return Rational.WriteTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& Rational) noexcept {
	return Rational.ReadFrom(istrm);
}

#endif
