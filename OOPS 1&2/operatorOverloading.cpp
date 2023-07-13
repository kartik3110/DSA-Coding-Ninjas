#include <iostream>
using namespace std;
class Fraction
{
private:
    int num, den;

public:
    Fraction(int num, int den)
    {
        this->num = num;
        this->den = den;
    }
    void simplify()
    {
        int gcd = 0;
        for (int i = 1; i <= num && i <= den; i++)
        {
            if (num % i == 0 && den % i == 0)
            {
                gcd = i;
            }
        }
        num = num / gcd;
        den = den / gcd;
    }
    // pre decrement
    Fraction &operator++()
    {
        num += den;
        simplify();
        return *this;
    }
    // post decrement(int in the args signifies )
    Fraction operator++(int)
    {
        Fraction f_old(num, den);
        num += den;
        simplify();
        f_old.simplify();
        return f_old;
    }

    Fraction &operator+=(Fraction f2)
    {
        // find lcm
        int lcm = den * f2.den;
        int x = lcm / num;
        int y = lcm / (f2.num);
        num = num * x + (f2.num) * y;
        den = lcm;
        simplify();
        return *this;
    }

    void const print()
    {
        cout << num << "/" << den << endl;
    }
};

int main()
{
    Fraction f1(2, 3);
    f1.print();
    f1++.print();
    f1.print();
    (++f1).print();
}