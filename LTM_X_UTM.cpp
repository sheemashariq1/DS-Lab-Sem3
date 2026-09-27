// Product of one Lower Triangular Matrix (LTM)
// and one Upper Triangular Matrix (UTM)

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

            for(int k = 0; k < n; k++)
            {
                c.a[i][j] += a[i][k] * b.a[k][j];
            }
        }
    }

    return c;
}

int main()
{
    Matrix L, U, C;

    cout << "Enter Lower Triangular Matrix:\n";
    L.input();

    cout << "\nEnter Upper Triangular Matrix:\n";
    U.input();

    C = L.multiply(U);

    cout << "\nLower Triangular Matrix:\n";
    L.display();

    cout << "\nUpper Triangular Matrix:\n";
    U.display();

    cout << "\nProduct (LTM x UTM):\n";
    C.display();

    return 0;
}