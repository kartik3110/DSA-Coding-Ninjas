#include <iostream>
using namespace std;
class polynomial
{
    int *degCoeff; // indices are degrees and elements ar coefficients
    int size;

public:
    polynomial()
    {
        degCoeff = new int[5];
        size = 5;
        for (int i = 0; i < size; i++)
        {
            degCoeff[i] = 0;
        }
    }
    void setCoefficient(int degree, int coeff)
    {
        while (degree >= size)
        {
            int *newarr = new int[2 * size];
            for (int i = 0; i < 2 * size; i++)
            {
                newarr[i] = 0;
            }
            for (int i = 0; i < (size); i++)
            {
                newarr[i] = degCoeff[i];
            }
            delete[] degCoeff;
            degCoeff = newarr;
            size *= 2;
        }

        degCoeff[degree] = coeff;
    }

    polynomial(polynomial const &p) // copy constructor
    {
        size = p.size;
        degCoeff = new int[size];
        for (int i = 0; i < size; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
    }
    void operator=(polynomial p)
    {
        size = p.size;
        degCoeff = new int[size];
        for (int i = 0; i < size; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
    }
    polynomial operator+(polynomial const &p) // my solution
    {
        polynomial p3;
        int Max = max(size, p.size);
        p3.size = Max;
        int *newarray = new int[Max];

        if (size >= p.size)
        {
            for (int i = 0; i < p3.size; i++)
            {
                newarray[i] = degCoeff[i];
            }
            for (int i = 0; i < p.size; i++)
            {
                newarray[i] += p.degCoeff[i];
            }
        }
        else
        {
            for (int i = 0; i < p.size; i++)
            {
                newarray[i] = p.degCoeff[i];
            }
            for (int i = 0; i < size; i++)
            {
                newarray[i] += degCoeff[i];
            }
        }
        delete[] p3.degCoeff;
        p3.degCoeff = newarray;
        return p3;
    }
    polynomial operator-(polynomial &p2) // actual solution
    {
        int Max = max(size, p2.size);

        if (Max == size)
        {
            for (int i = p2.size; i < size; i++)
            {
                p2.setCoefficient(i, 0);
            }
        }
        if (Max == p2.size)
        {
            for (int i = size; i < p2.size; i++)
            {
                setCoefficient(i, 0);
            }
        }
        polynomial p3;
        for (int i = 0; i < Max; i++)
        {
            p3.setCoefficient(i, degCoeff[i] - p2.degCoeff[i]);
        }
        return p3;
    }
    polynomial operator*(polynomial &p)
    {
        polynomial p3;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < p.size; j++)
            {
                int existingElement; // bcz same degree terms will be added.
                if (i + j >= p3.size)
                {
                    existingElement = 0;
                }
                else
                {
                    existingElement = p3.degCoeff[i + j];
                }
                p3.setCoefficient(i + j, existingElement + (degCoeff[i] * p.degCoeff[j])); // i+j as degrees are added
            }
        }
        return p3;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            if (degCoeff[i] != 0)
            {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
};
int main()
{
    polynomial p1;
    p1.setCoefficient(3, 1);
    p1.setCoefficient(1, 2);
    p1.setCoefficient(7, 3);
    p1.print();
    polynomial p2;
    p2.setCoefficient(2, 7);
    p2.setCoefficient(1, 8);
    p2.print();
    polynomial p3 = p1 * p2;
    p3.print();
    return 0;
}