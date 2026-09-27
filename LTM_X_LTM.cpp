// Product of two Lower Triangular Matrices (LTMs)

#include <iostream>
using namespace std;

class Matrix
{
    int **a;
    int n;

public:
    void input();
    void display();
    Matrix multiply(Matrix b);
};

void Matrix::input()
{
    cout << "Enter order: ";
    cin >> n;

    a = new int *[n];

    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void Matrix::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }
}

Matrix Matrix::multiply(Matrix b)
{
    Matrix c;

    c.n = n;

    c.a = new int *[n];

    for (int i = 0; i < n; i++)
        c.a[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c.a[i][j] = 0;
            if (j <= i)
            {
                for (int k = j; k <= i; k++)
                {
                    c.a[i][j] += a[i][k] * b.a[k][j];
                }
            }
        }
    }

    return c;
}

int main()
{
    Matrix A, B, C;

    cout << "Enter first Lower Triangular Matrix:\n";
    A.input();

    cout << "\nEnter second Lower Triangular Matrix:\n";
    B.input();

    C = A.multiply(B);

    cout << "\nFirst Matrix:\n";
    A.display();

    cout << "\nSecond Matrix:\n";
    B.display();

    cout << "\nProduct:\n";
    C.display();

    return 0;
}