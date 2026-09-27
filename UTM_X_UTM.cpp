// Product of two Upper Triangular Matrices (UTMs).

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

// Input function
void Matrix::input()
{
    cout << "Enter order: ";
    cin >> n;

    a = new int*[n];

    for(int i = 0; i < n; i++)
        a[i] = new int[n];

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

// Display function
void Matrix::display()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }
}

// Multiplication function
Matrix Matrix::multiply(Matrix b)
{
    Matrix c;

    c.n = n;

    c.a = new int*[n];

    for(int i = 0; i < n; i++)
        c.a[i] = new int[n];

    // Multiplication
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            c.a[i][j] = 0;

            // Only calculate upper triangular part
            if(j >= i)
            {
                for(int k = i; k <= j; k++)
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

    cout << "Enter first Upper Triangular Matrix:\n";
    A.input();

    cout << "\nEnter second Upper Triangular Matrix:\n";
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