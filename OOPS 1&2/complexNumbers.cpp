#include <iostream>
using namespace std;
class ComplexNumbers
{
private:
    int real;
    int imaginary;

public:
    ComplexNumbers(int real, int imag)
    {
        (*this).real = real;
        imaginary = imag;
    }

    void plus(ComplexNumbers const &adder)
    {
        this->real += adder.real; // this is optional
        this->imaginary += adder.imaginary;
    }
    void multiply(ComplexNumbers const &m)
    {
        int r = (real * m.real) - (imaginary * m.imaginary);
        imaginary = (real * m.imaginary) + (imaginary * m.real);
        real = r;
    }
    void print()
    {
        cout << real << "+" << imaginary << "i";
    }
};
int main()
{
    ComplexNumbers number(3, 4);
    ComplexNumbers number2(2, 6);
    number.multiply(number2);
    number.print();
    return 0;
}
