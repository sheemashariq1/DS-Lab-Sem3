// Product of one Upper Triangular Matrix (UTM)
// and one Lower Triangular Matrix (LTM)

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

            for (int k = 0; k < n; k++)
            {
                c.a[i][j] += a[i][k] * b.a[k][j];
            }
        }
    }

    return c;
}

int main()
{
    Matrix U, L, C;

    cout << "Enter Upper Triangular Matrix:\n";
    U.input();

    cout << "\nEnter Lower Triangular Matrix:\n";
    L.input();

    C = U.multiply(L);

    cout << "\nUpper Triangular Matrix:\n";
    U.display();

    cout << "\nLower Triangular Matrix:\n";
    L.display();

    cout << "\nProduct (UTM x LTM):\n";
    C.display();

    return 0;
}

// Using readUTM(int** matrix, int n), readLTM(int** matrix, int n), printMatrix(int** matrix, int n) and mul(int **matrix1, int **matrix2, int n) functions to perform the same operation.

#include <iostream>
using namespace std;

// Read UTM
void readUTM(int **q, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i <= j)
                cin >> q[i][j];
            else
                q[i][j] = 0;
        }
    }
}

// Read LTM
void readLTM(int **q, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i >= j)
                cin >> q[i][j];
            else
                q[i][j] = 0;
        }
    }
}

// Print matrix
void printMatrix(int **q, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << q[i][j] << "\t";
        }
        cout << endl;
    }
}

// UTM × LTM
int **mul(int **a, int **b, int n)
{
    int **c = new int*[n];

    for(int i = 0; i < n; i++)
        c[i] = new int[n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            c[i][j] = 0;

            for(int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;
}

int main()
{
    int n;

    cout << "Enter order: ";
    cin >> n;

    // Allocate UTM
    int **a = new int*[n];

    for(int i = 0; i < n; i++)
        a[i] = new int[n];


    int **b = new int*[n];

    for(int i = 0; i < n; i++)
        b[i] = new int[n];


    cout << "Enter UTM:\n";
    readUTM(a, n);

    cout << "Enter LTM:\n";
    readLTM(b, n);

    int **c = mul(a, b, n);

    cout << "\nUTM:\n";
    printMatrix(a, n);

    cout << "\nLTM:\n";
    printMatrix(b, n);

    cout << "\nUTM x LTM:\n";
    printMatrix(c, n);

    return 0;
}