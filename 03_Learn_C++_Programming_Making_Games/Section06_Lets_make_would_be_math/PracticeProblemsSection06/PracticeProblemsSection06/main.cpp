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
    Fraction();
    Fraction(int arg1, int arg2);
    ~Fraction() {}

    Fraction operator+(Fraction frac) const;
    Fraction operator-(Fraction frac) const;

    Fraction operator*(Fraction frac) const;
    Fraction operator/(Fraction frac) const;

    Fraction& operator+=(Fraction frac);
    Fraction& operator-=(Fraction frac);

    Fraction& operator*=(Fraction frac);
    Fraction& operator/=(Fraction frac);

    bool operator==(Fraction& frac) const;
    bool operator<(Fraction& frac) const;
    bool operator>(Fraction& frac) const;
    bool operator<=(Fraction& frac) const;
    bool operator>=(Fraction& frac) const;

    int gcd(int a, int b) const;
    void compare(Fraction frac) const;
    inline int getNumerator() const;
    inline int getDenominator() const;
    void print() const;

    const static int cNumerator = 1;
    const static int cDenominatorHalf = 2;
    const static int cDenominatorThird = 3;
    const static int cDenominatorFourth = 4;
    const static int cDenominatorFifth = 5;

    friend std::ostream& operator<<(std::ostream& consoleOut, const Fraction& frac);
};

Fraction::Fraction() : Fraction(0, 1) {}
Fraction::Fraction(int arg1, int arg2) : mNumerator(arg1), mDenominator(arg2)
{
    simplify();
}


Fraction Fraction::operator+(Fraction frac) const
{
    return Fraction((mNumerator * frac.mDenominator) + (frac.mNumerator * mDenominator), (mDenominator * frac.mDenominator));
}

Fraction Fraction::operator-(Fraction frac) const
{
    if ((mNumerator * frac.mDenominator) - (frac.mNumerator * mDenominator) == 0)
        return Fraction(0, 0);
    else
        return Fraction((mNumerator * frac.mDenominator) - (frac.mNumerator * mDenominator), (mDenominator * frac.mDenominator));
}

Fraction Fraction::operator*(Fraction frac) const
{
    return Fraction(mNumerator * frac.mNumerator, mDenominator * frac.mDenominator);
}

Fraction Fraction::operator/(Fraction frac) const
{
    return Fraction(mNumerator * frac.mDenominator, mDenominator * frac.mNumerator);
}

Fraction& Fraction::operator+=(Fraction frac)
{
    return *this = *this + frac;
}

Fraction& Fraction::operator-=(Fraction frac)
{
    return *this = *this - frac;
}

Fraction& Fraction::operator*=(Fraction frac)
{
    *this = *this * frac;
    return *this;
}

Fraction& Fraction::operator/=(Fraction frac)
{
    *this = *this / frac;
    return *this;
}

bool Fraction::operator==(Fraction& frac) const
{
    bool equal = ((mNumerator * frac.mDenominator) == (frac.mNumerator * mDenominator)) ? true : false;
    return equal;
}

bool Fraction::operator<(Fraction& frac) const
{
    bool equal = ((mNumerator * frac.mDenominator) < (frac.mNumerator * mDenominator)) ? true : false;
    return equal;
}

bool Fraction::operator>(Fraction& frac) const
{
    bool equal = ((mNumerator * frac.mDenominator) > (frac.mNumerator * mDenominator)) ? true : false;
    return equal;
}

bool Fraction::operator<=(Fraction& frac) const
{
    bool equal = ((mNumerator * frac.mDenominator) <= (frac.mNumerator * mDenominator)) ? true : false;
    return equal;
}

bool Fraction::operator>=(Fraction& frac) const
{
    bool equal = ((mNumerator * frac.mDenominator) >= (frac.mNumerator * mDenominator)) ? true : false;
    return equal;
}


int Fraction::gcd(int a, int b) const
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b % a, a);
    }
}

void Fraction::compare(Fraction frac) const
{
    if (*this == frac)
        cout << "Fraction are equal" << endl;
    else if (*this < frac)
        cout << "Fraction 1 is smaller" << endl;
    else if (*this > frac)
        cout << "Fraction 1 is bigger" << endl;
}

inline int Fraction::getNumerator() const
{
    return mNumerator;
}

inline int Fraction::getDenominator() const
{
    return mDenominator;
}

void Fraction::simplify()
{
    if (mNumerator == 0 && mDenominator == 0)
    {
        //do nothing
    }
    else
    {
        int divisor = gcd(mNumerator, mDenominator);
        mDenominator /= divisor;
        mNumerator /= divisor;
    }
}


std::ostream& operator<<(std::ostream& consoleOut, const Fraction& frac)
{
    consoleOut << frac.mNumerator << "/" << frac.mDenominator << endl;
    return consoleOut;
}


int main()
{
    Fraction fraction1(Fraction::cNumerator, Fraction::cDenominatorFifth);
    Fraction fraction2(1, 5);
    Fraction resultFraction;

    //Example math operation
    fraction1 /= fraction2;
    cout << fraction1 << endl;

    //Example compare
    fraction1.compare(fraction2);

    return 0;
}