#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Term
{
public:
	Term(int a, float b) :c(a), p(b) {};

	Term operator+(float value);
	Term operator+(Term& other);

	Term operator-(float value);
	Term operator-(Term& other);

	Term operator*(float value);
	Term operator*(Term& other);

	Term operator/(float value);
	Term operator/(Term& other);

	Term operator+=(Term& other);

	Term operator-=(Term& other);

	Term operator*=(Term& other);

	Term operator/=(Term& other);

	Term operator=(Term& other);

	bool operator>(float value);
	bool operator>(Term& other);

	bool operator<(float value);
	bool operator<(Term& other);

	bool operator>=(float value);
	bool operator>=(Term& other);

	bool operator<=(float value);
	bool operator<=(Term& other);

	bool operator==(float value);
	bool operator==(Term& other);

	bool operator!=(float value);
	bool operator!=(Term& other);

	Term operator~();

	void operator++();
	void operator--();

	float operator()(float a) { return (pow(a, p)) * c; }

	int p;
	float c;
	string Enter;
	string error;
private:


};

Term Term::operator+(float value)
{
	if (p == 0) {
		c += value;
		return *this;
	}
	else if (c == 0) {
		c = value;
		p = 0;
		return *this;
	}
	throw bad_exception();
}

Term Term::operator+(Term& other)
{
	if (other.p == p)
	{
		c += other.c;
		return *this;
	}
	if (other.c == 0) {
		return Term(c, p);
	}
	if (c == 0) {
		return Term(other.c, other.p);
	}
	throw bad_exception();
}

Term Term::operator-(float value)
{
	if (p == 0) {
		c -= value;
		return *this;
	}
	else if (c == 0) {
		c = value;
		p = 0;
		return *this;
	}
	throw bad_exception();
}

Term Term::operator-(Term& other)
{
	if (other.p == p)
	{
		c -= other.c;
		return *this;
	}
	if (other.c == 0) {
		return Term(c, p);
	}
	if (c == 0) {
		return Term(other.c, other.p);
	}
	throw bad_exception();
}

Term Term::operator*(float value)
{
	c *= value;
	return *this;

}

Term Term::operator*(Term& other)
{
	return Term(c * other.c, p + other.p);
}

Term Term::operator/(float value)
{
	if (value == 0) {
		throw bad_exception();
	}
	c /= value;
	return *this;

}

Term Term::operator/(Term& other)
{
	if (other.c == 0) {
		throw bad_exception();
	}
	return Term(c /= other.c, p -= other.p);

}

void Term::operator++()
{
	if (p == 0)
	{
		c += 1;
	}
	if (c == 0)
	{
		c += 1;
	}
	throw bad_exception();
}

void Term::operator--()
{
	if (p == 0)
	{
		c -= 1;
	}
	if (c == 0)
	{
		c -= 1;
	}
	throw bad_exception();
}

Term Term::operator+=(Term& other)
{
	if (other.p == p)
	{
		c += other.c;
		return *this;
	}
	if (other.c == 0) {
		return Term(c, p);
	}
	if (c == 0) {
		return Term(other.c, other.p);
	}
	throw bad_exception();
}

Term Term::operator-=(Term& other)
{
	if (other.p == p)
	{
		c -= other.c;
		return *this;
	}
	if (other.c == 0) {
		return Term(c, p);
	}
	if (c == 0) {
		return Term(other.c, other.p);
	}
	throw bad_exception();
}

Term Term::operator*=(Term& other)
{
	c *= other.c;
	p += other.p;
	return *this;

}

Term Term::operator/=(Term& other)
{

	if (other.c == 0) {
		throw bad_exception();
	}
	else
	{
		c /= other.c;
		p -= other.p;
		return *this;
	}
}

Term Term::operator=(Term& other)
{
	p = other.p;
	c = other.c;
	return *this;
}

bool Term::operator>(float value)
{
	if (p == 0 && c > value) { return true; }
	return false;
}

bool Term::operator>(Term& other)
{
	if (p > other.p) { return true; }
	if (p == other.p && c > other.c) { return true; }
	return false;
}

bool Term::operator<(float value)
{
	if (p == 0 && c < value) { return true; }
	return false;
}

bool Term::operator<(Term& other)
{
	if (p < other.p) { return true; }
	if (p == other.p && c < other.c) { return true; }
	return false;
}

bool Term::operator>=(float value)
{
	if (p == 0 && c >= value) { return true; }
	return false;
}

bool Term::operator>=(Term& other)
{
	if (p >= other.p) { return true; }
	if (p == other.p && c >= other.c) { return true; }
	return false;
}

bool Term::operator<=(float value)
{
	if (p == 0 && c <= value) { return true; }
	return false;
}

bool Term::operator<=(Term& other)
{
	if (p <= other.p) { return true; }
	if (p == other.p && c <= other.c) { return true; }
	return false;
}

bool Term::operator==(float value)
{
	if (p == 0 && c == value) { return true; }
	return false;
}

bool Term::operator==(Term& other)
{
	if (p == other.p && c == other.c) { return true; }
	return false;
}

bool Term::operator!=(float value)
{
	if (p == 0 && c != value) { return true; }
	return false;
}

bool Term::operator!=(Term& other)
{
	if (p != other.p) { return true; }
	if (p == other.p && c != other.c) { return true; }
	return false;
}

Term Term::operator~()
{
	if (p <= 0) {
		return Term(0, 0);
	}
	else
	{
		c *= p;
		p -= 1;
		return *this;
	}
}

ostream& operator<<(ostream& stream, Term& other)
{
	if (other.p == 0 && other.c != 0)
	{
		return stream << other.c << "x";
	}
	if (other.p != 0 && other.c == 0)
	{
		return stream << "x^" << other.p;
	}
	if (other.p == 0 && other.c == 0)
	{
		return stream << "" << other.p;
	}
	return stream << other.c << "x^" << other.p;
}

int main()
{

}
