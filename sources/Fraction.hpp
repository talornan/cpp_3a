#pragma once

#include <iostream>
#include <numeric>
#include <cmath>
#include <limits>

constexpr int PRECISION = 1000;

namespace ariel
{
	class Fraction
	{
	private:
		int numerator;
		int denominator;
		void reduce();

	public:
		Fraction(): numerator(0), denominator(1) { };
		Fraction(float number);
		Fraction(int numerator, int denominator);

		int getNumerator() const
		{
			return numerator;
		}
		int getDenominator() const
		{
			return denominator;
		}

		friend std::ostream &operator<<(std::ostream &outp, const Fraction &frac)
		{
			outp << frac.numerator << "/" << frac.denominator;
			return outp;
		}

		friend std::istream &operator>>(std::istream &inp, Fraction &frac)
		{
			int nomer = 0;
			int dover = 0;

			inp >> nomer >> dover;

			if (inp.fail())
			{
				throw std::runtime_error("Invalid input");
			}

			if (dover == 0)
			{
				throw std::runtime_error("Division by 0");
			}

			frac.numerator = nomer;
			frac.denominator = dover;

			frac.reduce();
			return inp;
		}

		Fraction operator+(const Fraction &other) const;
		Fraction operator-(const Fraction &other) const;
		Fraction operator*(const Fraction &other) const;
		Fraction operator/(const Fraction &other) const;

		bool operator==(const Fraction &other) const;
		bool operator!=(const Fraction &other) const
		{
			return !(*this == other);
		}
		bool operator>(const Fraction &other) const;
		bool operator<(const Fraction &other) const;
		bool operator<=(const Fraction &other) const
		{
			return !(*this > other);
		}
		bool operator>=(const Fraction &fract) const
		{
			return !(*this < fract);
		}

		Fraction operator++();
		Fraction operator++(int);
		Fraction operator--();
		Fraction operator--(int);

		// float overloaded operator
		friend bool operator==(const Fraction &fruct1, float other)
		{
			return fruct1 == Fraction(other);
		}
		friend bool operator!=(const Fraction &fruct1, float other)
		{
			return fruct1 != Fraction(other);
		}
		friend bool operator>(const Fraction &fruct1, float other)
		{
			return fruct1 > Fraction(other);
		}
		friend bool operator<(const Fraction &fruct1, float other)
		{
			return fruct1 < Fraction(other);
		}
		friend bool operator<=(const Fraction &fruct1, float other)
		{
			return fruct1 <= Fraction(other);
		}
		friend bool operator>=(const Fraction &fruct1, float other)
		{
			return fruct1 >= Fraction(other);
		}

		friend bool operator==(const float other, const Fraction &fruct1)
		{
			return Fraction(other) == fruct1;
		}
		friend bool operator!=(const float other, const Fraction &fruct1)
		{
			return Fraction(other) != fruct1;
		}
		friend bool operator>(const float other, const Fraction &fruct1)
		{
			return Fraction(other) > fruct1;
		}
		friend bool operator<(const float other, const Fraction &fruct1)
		{
			return Fraction(other) < fruct1;
		}
		friend bool operator<=(const float other, const Fraction &fruct1)
		{
			return Fraction(other) <= fruct1;
		}
		friend bool operator>=(const float other, const Fraction &fruct1)
		{
			return Fraction(other) >= fruct1;
		}

		friend Fraction operator+(const Fraction &fruct1, float other)
		{
			return fruct1 + Fraction(other);
		}
		friend Fraction operator-(const Fraction &fruct1, float other)
		{
			return fruct1 - Fraction(other);
		}
		friend Fraction operator*(const Fraction &fruct1, float other)
		{
			return fruct1 * Fraction(other);
		}
		friend Fraction operator/(const Fraction &fruct1, float other)
		{
			return fruct1 / Fraction(other);
		}

		friend Fraction operator+(float other, const Fraction &fruct1)
		{
			return Fraction(other) + fruct1;
		}
		friend Fraction operator-(float other, const Fraction &fruct1)
		{
			return Fraction(other) - fruct1;
		}
		friend Fraction operator*(float other, const Fraction &fruct1)
		{
			return Fraction(other) * fruct1;
		}
		friend Fraction operator/(float other, const Fraction &fruct1)
		{
			return Fraction(other) / fruct1;
		}
	};
}