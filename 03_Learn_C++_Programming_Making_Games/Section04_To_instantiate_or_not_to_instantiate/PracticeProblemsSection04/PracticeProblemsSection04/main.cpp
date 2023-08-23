#include <iostream>
#include <string>
#include <numeric>

using std::string;
using std::cout;
using std::endl;

class Fraction
{
private:
    int mNumerator = 0;
    int mDenominator = 0;
    void simplify();

public:
    //Constructors
    Fraction();
    Fraction(int arg1, int arg2);

    //Math Functions
    Fraction add(Fraction frac) const;
    Fraction substract(Fraction frac) const;
    Fraction multiply(Fraction frac);
    Fraction divide(Fraction frac);
    int gcd(int a, int b) const;
    void compare(Fraction frac) const;

    //Output Functions
    inline int getNumerator() const;
    inline int getDenominator() const;
    void print() const;

    //Const static variables

    const static int cNumerator = 1;
    const static int cDenominatorHalf = 2;
    const static int cDenominatorThird = 3;
    const static int cDenominatorFourth = 4;
    const static int cDenominatorFifth = 5;
};

//Constructors
Fraction::Fraction() : Fraction(0, 1) {}
Fraction::Fraction(int arg1, int arg2) : mNumerator(arg1), mDenominator(arg2)
{
    simplify();
}

//Functions
Fraction Fraction::add(Fraction frac) const
{
    return Fraction((mNumerator * frac.mDenominator) + (frac.mNumerator * mDenominator), (mDenominator * frac.mDenominator));
}

Fraction Fraction::substract(Fraction frac) const
{
    return Fraction((mNumerator * frac.mDenominator) - (frac.mNumerator * mDenominator), (mDenominator * frac.mDenominator));
}

Fraction Fraction::multiply(Fraction frac)
{
    return Fraction(mNumerator * frac.mNumerator, mDenominator * frac.mDenominator);
}

Fraction Fraction::divide(Fraction frac)
{
    return Fraction(mNumerator * frac.mDenominator, mDenominator * frac.mNumerator);
}

int Fraction::gcd(int a, int b) const
{
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}

inline int Fraction::getNumerator() const
{
    return mNumerator;
}

inline int Fraction::getDenominator() const
{
    return mDenominator;
}

void Fraction::print() const
{
    cout << mNumerator << "/" << mDenominator << endl;
}

void Fraction::simplify()
{
    int divisor = gcd(mNumerator, mDenominator);
    mDenominator /= divisor;
    mNumerator /= divisor;
}

void Fraction::compare(Fraction frac) const
{
    if ((mNumerator * frac.mDenominator) > (frac.mNumerator * mDenominator))
        cout << "Fraction 1 is bigger" << endl;
    else if ((mNumerator * frac.mDenominator) < (frac.mNumerator * mDenominator))
        cout << "Fraction 1 is smaller" << endl;
    else
        cout << "Both fractions are equal" << endl;
}

int main()
{
    Fraction fraction1(Fraction::cNumerator, Fraction::cDenominatorFifth);
    Fraction fraction2(1, 5);
    Fraction resultFraction;

    //Example division
    resultFraction = fraction1.divide(fraction2);
    resultFraction.print();

    //Example compare
    fraction1.compare(fraction2);


    //Get-functions
    int numerator = resultFraction.getNumerator();
    int denominator = resultFraction.getDenominator();

    cout << "Numerator: " << numerator << "\tDenominator: " << denominator << endl;

    return 0;
}