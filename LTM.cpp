// insert(row,cols,value) ,determinant(), display() functions for lower triangular matrix using pointers

#include <iostream>
using namespace std;

class lower
{
    int **arr;
    int n;

public:
    lower(int size);
    void insert(int i, int j, int value);
    double determinant();
    void display();
};
lower::lower(int size)
{
    n = size;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[i + 1];
    }
}
void lower::insert(int i, int j, int value)
{
    if (i >= j)
    {
        arr[i][j] = value;
    }
    else
    {
        arr[i][j] = 0;
    }
}
double lower::determinant()
{
    double det = 1;
    for (int i = 0; i < n; i++)
    {
        det *= arr[i][i];
    }
    return det;
}
void lower::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
                cout << arr[i][j] << "\t";
            else
                cout << 0 << "\t";
        }

        cout << "\n";
    }
}

int main()
{
    int n, value;
    cout << "Enter the size of the lower triangular matrix: ";
    cin >> n;

    lower l(n);

    cout << "Enter the elements of the lower triangular matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "Element at (" << i << ", " << j << "): ";
            cin >> value;
            l.insert(i, j, value);
        }
    }

    cout << "\nThe lower triangular matrix is:\n";
    l.display();

    double det = l.determinant();
    cout << "\nDeterminant of the matrix: " << det << endl;

    return 0;
}