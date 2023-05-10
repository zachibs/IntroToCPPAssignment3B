#pragma once
#include <iostream>
#include <limits.h>

using namespace std;

namespace ariel{};

class Fraction{
public:
    int numerator;
    int denominator;

    Fraction();
    Fraction(int, int);
    Fraction(float);
    
    Fraction operator+(const Fraction &);
    Fraction operator-(const Fraction &); 
    Fraction operator/(const Fraction &);
    Fraction operator*(const Fraction &);
    Fraction operator+(float);
    Fraction operator-(float);
    Fraction operator*(float);
    Fraction operator/(float);
    Fraction &operator++();
    Fraction operator++(int);
    Fraction &operator--();
    Fraction operator--(int);

    bool operator<=(const Fraction &) const;
    bool operator>=(const Fraction &) const;
    bool operator<(const Fraction &) const;
    bool operator>(const Fraction &) const;
    bool operator==(const Fraction &) const;
    bool operator<=(float) const;
    bool operator>=(float) const;
    bool operator<(float) const;
    bool operator>(float) const;
    bool operator==(float) const;

    friend Fraction operator+(float, const Fraction &);
    friend Fraction operator-(float, const Fraction &);
    friend Fraction operator/(float, const Fraction &);
    friend Fraction operator*(float, const Fraction &);
    friend bool operator<=(float, const Fraction &);
    friend bool operator>=(float, const Fraction &);
    friend bool operator<(float, const Fraction &);
    friend bool operator>(float, const Fraction &);
    friend bool operator==(float, const Fraction &);
    friend ostream &operator<<(ostream &, const Fraction &);
    friend istream &operator>>(istream &, Fraction &);

    void reduce();
    int gcd(int, int);

    int getNumerator() const;
    int getDenominator() const;
    void isOverflow(double, double);
};