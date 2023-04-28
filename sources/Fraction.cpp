#include "Fraction.hpp"

using namespace std;

namespace ariel
{
	Fraction::Fraction(float number)
	{
		numerator = (int)(number * PRECISION);
		denominator = PRECISION;

		reduce();
	}

	Fraction::Fraction(int numer, int denom): numerator(numer), denominator(denom)
	{
		if (denom == 0)
		{
			throw invalid_argument("Division by 0");
		}

		reduce();
	}

	void Fraction::reduce()
	{
		int common_factor = gcd(numerator, denominator);
		numerator /= common_factor;
		denominator /= common_factor;
		if (denominator < 0)
		{
			numerator *= -1;
			denominator *= -1;
		}
	}

	Fraction Fraction::operator+(const Fraction &other) const
	{
		if ((other.denominator > 0 && numerator > std::numeric_limits<int>::max() / other.denominator) || (other.denominator < 0 && numerator < std::numeric_limits<int>::max() / other.denominator))
        {
			throw overflow_error("Overflow");
        }

		if ((denominator > 0 && other.denominator > std::numeric_limits<int>::max() / denominator) || (denominator < 0 && other.denominator < std::numeric_limits<int>::max() / denominator))
        {
			throw overflow_error("Overflow");
        }

		if (((other.numerator * denominator) > 0 && (numerator * other.denominator) > (std::numeric_limits<int>::max() - (other.numerator * denominator))) || ((other.numerator * denominator) < 0 && (numerator * other.denominator) < std::numeric_limits<int>::min() - (other.numerator * denominator)))
		{
			throw overflow_error("Overflow");
		}

		if ((other.denominator > 0 && denominator > std::numeric_limits<int>::max() / other.denominator) || (other.denominator < 0 && denominator < std::numeric_limits<int>::max() / other.denominator))
		{
			throw overflow_error("Overflow");
		}

		int new_numerator = numerator * other.denominator + other.numerator * denominator;
		int new_denominator = denominator * other.denominator;

		return Fraction(new_numerator, new_denominator);
	}

	Fraction Fraction::operator-(const Fraction &other) const
	{
		if ((other.denominator > 0 && numerator > std::numeric_limits<int>::max() / other.denominator) || (other.denominator < 0 && numerator < std::numeric_limits<int>::max() / other.denominator))
        {
			throw overflow_error("Overflow");
        }

		if ((denominator > 0 && other.denominator > std::numeric_limits<int>::max() / denominator) || (denominator < 0 && other.denominator < std::numeric_limits<int>::max() / denominator))
        {
			throw overflow_error("Overflow");
        }

		if (((other.numerator * denominator) < 0 && (numerator * other.denominator) > (std::numeric_limits<int>::max() + (other.numerator * denominator))) || ((other.numerator * denominator) > 0 && (numerator * other.denominator) < std::numeric_limits<int>::min() + (other.numerator * denominator)))
		{
			throw overflow_error("Overflow");
		}

		if ((other.denominator > 0 && denominator > std::numeric_limits<int>::max() / other.denominator) || (other.denominator < 0 && denominator < std::numeric_limits<int>::max() / other.denominator))
		{
			throw overflow_error("Overflow");
		}
		int new_numerator = numerator * other.denominator - other.numerator * denominator;
		int new_denominator = denominator * other.denominator;
		return Fraction(new_numerator, new_denominator);
	}

	Fraction Fraction::operator*(const Fraction &other) const
	{
		if ((other.numerator > 0 && numerator > std::numeric_limits<int>::max() / other.numerator) || (other.numerator < 0 && numerator < std::numeric_limits<int>::max() / other.numerator))
		{
			throw overflow_error("Overflow");
		}

		if ((other.denominator > 0 && denominator > std::numeric_limits<int>::max() / other.denominator) || (other.denominator < 0 && denominator < std::numeric_limits<int>::max() / other.denominator))
		{
			throw overflow_error("Overflow");
		}

		int new_numerator = numerator * other.numerator;
		int new_denominator = denominator * other.denominator;
		return Fraction(new_numerator, new_denominator);
	}

	Fraction Fraction::operator/(const Fraction &other) const
	{
		if (other.numerator == 0)
		{
			throw runtime_error("Division by 0");
		}

		if ((other.denominator > 0 && numerator > std::numeric_limits<int>::max() / other.denominator) || (other.denominator < 0 && numerator < std::numeric_limits<int>::max() / other.denominator))
		{
			throw overflow_error("Overflow");
		}

		if ((other.numerator > 0 && denominator > std::numeric_limits<int>::max() / other.numerator) || (other.numerator < 0 && denominator < std::numeric_limits<int>::max() / other.numerator))
		{
			throw overflow_error("Overflow");
		}

		int new_numerator = numerator * other.denominator;
		int new_denominator = denominator * other.numerator;
		return Fraction(new_numerator, new_denominator);
	}

	bool Fraction::operator==(const Fraction &other) const
	{
		const float THENUMBER = 1000.0;
        int opt1 = (int)(((float)numerator / (float)denominator) * THENUMBER);
        int opt2 = (int)(((float)other.numerator / (float)other.denominator) * THENUMBER);

        return (opt1 == opt2);
	}

	bool Fraction::operator>(const Fraction &other) const
	{
		double this_val = static_cast<double>(numerator) / denominator;
		double other_val = static_cast<double>(other.numerator) / other.denominator;
		return this_val > other_val;
	}

	bool Fraction::operator<(const Fraction &other) const
	{
		double this_val = static_cast<double>(numerator) / denominator;
		double other_val = static_cast<double>(other.numerator) / other.denominator;
		return this_val < other_val;
	}

	Fraction Fraction::operator++()
	{
		numerator += denominator;
		reduce();
		return *this;
	}

	Fraction Fraction::operator++(int)
	{
		Fraction tmp(*this);
		operator++();
		return tmp;
	}

	Fraction Fraction::operator--()
	{
		numerator -= denominator;
		reduce();
		return *this;
	}

	Fraction Fraction::operator--(int)
	{
		Fraction tmp(*this);
		operator--();
		return tmp;
	}
};