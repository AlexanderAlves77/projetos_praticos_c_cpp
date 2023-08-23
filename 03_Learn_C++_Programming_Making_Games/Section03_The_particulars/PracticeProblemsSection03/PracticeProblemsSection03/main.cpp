#include <iostream>
using namespace std;

class Fraction
{
public:
    Fraction();
    Fraction(int num, int denom);
    Fraction Add(Fraction b_frac) const;
    Fraction Subtract(Fraction b_frac) const;
    Fraction Multiply(Fraction b_frac)  const;
    Fraction Divide(Fraction b_frac) const;
    void Compare(Fraction a_frac, Fraction b_frac) const;
    void Print() const;

    static const Fraction half;
    static const Fraction third;
    static const Fraction quarter;
    static const Fraction fifth;

    inline int GetNumerator() const { return numerator; }
    inline int GetDenominator() const { return denominator; }

private:
    int numerator;
    int denominator;
    int divisor;
    void simplify();
};

Fraction::Fraction(int num, int denom)
{
    numerator = num;
    denominator = denom;
    simplify();
}


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}

Fraction::Fraction() :Fraction(0, 1) {}

const Fraction Fraction::half(1, 2);
const Fraction Fraction::third(1, 3);
const Fraction Fraction::quarter(1, 4);
const Fraction Fraction::fifth(1, 5);

void Fraction::simplify()
{
    divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

Fraction Fraction::Add(Fraction b_frac) const
{
    return Fraction((numerator * b_frac.denominator) + (b_frac.numerator * denominator), (denominator * b_frac.denominator));
}

Fraction Fraction::Subtract(Fraction b_frac) const
{
    return Fraction((numerator * b_frac.denominator) - (b_frac.numerator - denominator), (denominator * b_frac.denominator));
}

Fraction Fraction::Multiply(Fraction b_frac) const
{
    return Fraction(numerator * b_frac.numerator, denominator * b_frac.denominator);
}

Fraction Fraction::Divide(Fraction b_frac) const
{
    return Fraction(numerator * b_frac.denominator, denominator * b_frac.numerator);
}

void Fraction::Print() const
{
    std::cout << numerator << "/" << denominator;
}

int main()
{
    Fraction FirstFraction(1, 2), SecondFraction(2, 7), resultFraction;
    resultFraction = FirstFraction.Add(SecondFraction);
    resultFraction.Print();

    cout << endl;
    system("Pause");
    return 0;
}


