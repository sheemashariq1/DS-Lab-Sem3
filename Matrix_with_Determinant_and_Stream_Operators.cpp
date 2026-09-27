// Write a program by defining SMatrix class with >>, << and determinant() functions.

#include <iostream>
using namespace std;

class SMatrix
{
    int **a;
    int n;

public:
    // Constructor
    SMatrix()
    {
        n = 0;
        a = NULL;
    }

    // Input using >>
    friend istream &operator>>(istream &in, SMatrix &m)
    {
        cout << "Enter order: ";
        in >> m.n;

        // Dynamic memory allocation
        m.a = new int *[m.n];

        for (int i = 0; i < m.n; i++)
        {
            m.a[i] = new int[m.n];
        }

        cout << "Enter elements:\n";

        for (int i = 0; i < m.n; i++)
        {
            for (int j = 0; j < m.n; j++)
            {
                in >> m.a[i][j];
            }
        }

        return in;
    }

    // Output using <<
    friend ostream &operator<<(ostream &out, SMatrix &m)
    {
        for (int i = 0; i < m.n; i++)
        {
            for (int j = 0; j < m.n; j++)
            {
                out << m.a[i][j] << " ";
            }

            out << endl;
        }

        return out;
    }

    // Determinant using UTM
    int determinant()
    {
        int det = 1;

        // Convert into Upper Triangular Matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i][i] == 0)
                    return 0;

                int x = a[j][i] / a[i][i];

                for (int k = i; k < n; k++)
                {
                    a[j][k] = a[j][k] - x * a[i][k];
                }
            }
        }

        // Product of diagonal elements
        for (int i = 0; i < n; i++)
        {
            det = det * a[i][i];
        }

        return det;
    }

    // Destructor
    ~SMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] a[i];
        }

        delete[] a;
    }
};

int main()
{
    SMatrix m;

    cin >> m;

    cout << "\nMatrix:\n";
    cout << m;

    cout << "\nDeterminant = " << m.determinant();

    return 0;
}