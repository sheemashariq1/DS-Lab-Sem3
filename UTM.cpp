//  insert(row,cols,value) ,determinant(), display() functions for upper triangular matrix using pointers.

#include <iostream>
using namespace std;

class upper
{
    int **arr;
    int n;

public:
    upper(int size);

    void insert(int i, int j, int value);
    double determinant();
    void display();
};

upper::upper(int size)
{
    n = size;

    // Create row pointers
    arr = new int *[n];

    // Allocate only upper triangular elements
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n - i];
    }
}

void upper::insert(int i, int j, int value)
{
    if (i <= j)
    {
        // j-i because row starts from column i
        arr[i][j - i] = value;
    }
}

double upper::determinant()
{
    double det = 1;

    for (int i = 0; i < n; i++)
    {
        // Diagonal element is arr[i][0]
        det = det * arr[i][0];
    }

    return det;
}

void upper::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
            {
                cout << arr[i][j - i] << "\t";
            }
            else
            {
                cout << 0 << "\t";
            }
        }

        cout << endl;
    }
}

int main()
{
    int n, value;

    cout << "Enter size of UTM: ";
    cin >> n;

    upper u(n);

    cout << "Enter upper triangular matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << "Element at (" << i << "," << j << "): ";
            cin >> value;

            u.insert(i, j, value);
        }
    }

    cout << "\nUpper Triangular Matrix:\n";
    u.display();

    cout << "\nDeterminant = " << u.determinant();

    return 0;
}