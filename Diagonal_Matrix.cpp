// input(), display(), determinant() functions for diagonal matrix using pointers.

#include <iostream>
using namespace std;

class Matrix
{
    int **a;
    int n;

public:
    void input();
    void display();
    int determinant();
};

void Matrix::input()
{
    cout << "Enter order: ";
    cin >> n;

    a = new int *[n];

    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cin >> a[i][j];
            else
                a[i][j] = 0;
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

int Matrix::determinant()
{
    int det = 1;

    for (int i = 0; i < n; i++)
    {
        det = det * a[i][i];
    }

    return det;
}

int main()
{
    Matrix A;

    cout << "Enter Diagonal Matrix:\n";
    A.input();

    cout << "\nDiagonal Matrix:\n";
    A.display();

    cout << "\nDeterminant = " << A.determinant();

    return 0;
}