#include "Fraction.hpp"
using namespace ariel;
using namespace std;

Fraction::Fraction(): numerator(0), denominator(1){}

Fraction::Fraction(int numerator, int denominator){
    if(denominator == 0){
        throw invalid_argument("Division by 0");
    } else{
        this->numerator = numerator;
        this->denominator = denominator;
    }
    reduce();
}

Fraction::Fraction(float secondnumber): numerator(secondnumber * 1000), denominator(1000){
    reduce();
}

Fraction Fraction::operator+(const Fraction &secondnumber){ 
    double commonNum = (((double) this->numerator) * ((double) secondnumber.denominator) + ((double) secondnumber.numerator) * ((double) this->denominator));
    double commonDenom = (((double) this->denominator) * ((double) secondnumber.denominator));

    isOverflow(commonNum, commonDenom);
    Fraction fraction((int) commonNum, (int) commonDenom);
    fraction.reduce();
    return fraction;
}

Fraction Fraction::operator-(const Fraction &secondnumber){
    double commonNum = (((double) this->numerator) * ((double) secondnumber.denominator) - ((double) secondnumber.numerator) * ((double) this->denominator));
    double commonDenom = (((double) this->denominator) * ((double) secondnumber.denominator));

    isOverflow(commonNum, commonDenom);
    Fraction fraction((int) commonNum, (int) commonDenom);
    fraction.reduce();
    return fraction;
}

Fraction Fraction::operator/(const Fraction &secondnumber){
    if(!secondnumber.numerator){
        throw runtime_error("Division by 0");
    }

    double commonNum = (((double) this->numerator) * ((double) secondnumber.denominator));
    double commonDenom = (((double) this->denominator) * ((double) secondnumber.numerator));

    isOverflow(commonNum, commonDenom);
    Fraction fraction((int) commonNum, (int) commonDenom);
    fraction.reduce();
    return fraction;
    
}

Fraction Fraction::operator*(const Fraction &secondnumber){
    double commonNum = (((double) this->numerator) * ((double) secondnumber.numerator));
    double commonDenom = (((double) this->denominator) * ((double) secondnumber.denominator));

    isOverflow(commonNum, commonDenom);
    Fraction fraction((int) commonNum, (int) commonDenom);
    fraction.reduce();
    return fraction;
}

Fraction Fraction::operator+(float number){ 
    return *this + Fraction(number);
}

Fraction Fraction::operator-(float number){ 
    return *this - Fraction(number);
}

Fraction Fraction::operator/(float number){ 
    if(!number){
        throw runtime_error("Division by 0");
    }
    return *this / Fraction(number);
}

Fraction Fraction::operator*(float number){ 
    return *this * Fraction(number);
}

Fraction &Fraction::operator++(){ 
    this->numerator += this->denominator;
    this->reduce();
    return *this;
}

Fraction Fraction::operator++(int){ 
    Fraction tempFraction = *this;
    this->operator++();
    return tempFraction;
}

Fraction &Fraction::operator--(){ 
    this->numerator -= this->denominator;
    this->reduce();
    return *this;
}

Fraction Fraction::operator--(int){ 
    Fraction tempFraction = *this;
    this->operator--();
    return tempFraction;
}

bool Fraction::operator<=(const Fraction &fraction) const{ 
    bool isLess = *this < fraction;
    bool isEqual = *this == fraction;
    return isLess || isEqual;
}

bool Fraction::operator>=(const Fraction &fraction) const{ 
    bool isGreater = *this > fraction;
    bool isEqual = *this == fraction;
    return isGreater || isEqual;
}

bool Fraction::operator<(const Fraction &fraction) const{ 
    if((this->numerator * fraction.denominator) < (this->denominator * fraction.numerator)){
        return true;
    }
    return false;
}

bool Fraction::operator>(const Fraction &fraction) const{ 
    if((this->numerator * fraction.denominator) > (this->denominator * fraction.numerator)){
        return true;
    }
    return false;
}

bool Fraction::operator==(const Fraction &fraction) const{ 
    return (this->numerator == fraction.getNumerator()) && (this->denominator == fraction.getDenominator()) ;
}

bool Fraction::operator<=(float secondnumber) const{ 
    Fraction tempFraction(secondnumber);
    return *this <= tempFraction;
}

bool Fraction::operator>=(float secondnumber) const{ 
    Fraction tempFraction(secondnumber);
    return *this >= tempFraction;
}

bool Fraction::operator<(float secondnumber) const{ 
    Fraction tempFraction(secondnumber);
    return *this < tempFraction;
}

bool Fraction::operator>(float secondnumber) const{ 
    Fraction tempFraction(secondnumber);
    return *this > tempFraction;
}

bool Fraction::operator==(float secondnumber) const{ 
    Fraction tempFraction(secondnumber);
    return *this == tempFraction;
}

Fraction operator+(float number, const Fraction &fraction){ 
    Fraction tempFraction(number);
    return tempFraction + fraction;
}

Fraction operator-(float number, const Fraction &fraction){
    Fraction tempFraction(number);
    return tempFraction - fraction;
}

Fraction operator/(float number, const Fraction &fraction){ 
    Fraction tempFraction(number);
    return tempFraction / fraction;
}

Fraction operator*(float number, const Fraction &fraction){
    Fraction tempFraction(number);
    return tempFraction * fraction;
}

bool operator<=(float number, const Fraction &fraction){ 
    Fraction tempFraction(number);
    return tempFraction <= fraction;
}

bool operator>=(float number, const Fraction &fraction){ 
    Fraction tempFraction(number);
    return tempFraction >= fraction;
}

bool operator<(float number, const Fraction &fraction){ 
    Fraction tempFraction(number);
    return tempFraction < fraction;
}

bool operator>(float number, const Fraction &fraction){ 
    Fraction tempFraction(number);
    return tempFraction > fraction;
}


bool operator==(float number, const Fraction &fraction){ 
    Fraction tempFraction(number);
    return tempFraction == fraction;
}

ostream &operator<<(ostream &stream, const Fraction &fraction){
    return (stream << fraction.numerator << '/' << fraction.denominator);
}

istream &operator>>(istream &stream, Fraction &fraction){

    int numerator ,denominator;
    stream>>numerator>>denominator;

    if(stream.fail()){
        throw runtime_error("Not valid input");
    }

    if(denominator){
        fraction.numerator = numerator;
        fraction.denominator = denominator;
        fraction.reduce();
    }else{
        throw runtime_error("Denominator is zero");
    } 
    return stream;
}

void Fraction::reduce(){
    int currentGCD = gcd(this->numerator, this->denominator);
    this->numerator = this->numerator / currentGCD;
    this->denominator = this->denominator / currentGCD;

    if(this->denominator < 0){
        this->numerator = (-1) * this->numerator;
        this->denominator = (-1) * this->denominator;
    }
}

int Fraction::gcd(int numerator, int denominator){
    if(!denominator){
        return numerator;
    }
    return gcd(denominator, numerator % denominator);
}

int Fraction::getNumerator() const{
    return this->numerator;
}

int Fraction::getDenominator() const{
    return this->denominator;
}

void Fraction::isOverflow(double numerator, double denominator){
    if (numerator < INT_MIN || INT_MAX < numerator || denominator < INT_MIN || INT_MAX < denominator)
        throw std::overflow_error("Overflow");
    }