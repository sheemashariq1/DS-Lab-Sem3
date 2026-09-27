// Write a program to define a Matrix class with read(), print() and * operators.

#include <iostream>
using namespace std;

class Matrix
{
private:
    int **mat; // Pointer to a 2D dynamic array
    int rows;
    int cols;

public:
    // Parameterized constructor
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;

        // Dynamically allocate rows
        mat = new int *[rows];
        // Dynamically allocate columns for each row
        for (int i = 0; i < rows; i++)
        {
            mat[i] = new int[cols];
        }
    }

    // Destructor to clean up dynamically allocated memory
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }

    // Function to read matrix elements from the user
    void read()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> mat[i][j];
            }
        }
    }

    // Function to print the matrix elements
    void print()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Overloading the * operator for Matrix Multiplication
    Matrix operator*(const Matrix &other)
    {
        // Matrix multiplication condition: cols of 1st matrix must equal rows of 2nd matrix
        if (this->cols != other.rows)
        {
            cout << "\nError: Matrix dimensions do not match for multiplication!" << endl;
            // Return an empty 0x0 matrix object on error
            return Matrix(0, 0);
        }

        // The resulting matrix will have rows of 1st matrix and cols of 2nd matrix
        Matrix result(this->rows, other.cols);

        // Perform standard matrix multiplication matrix logic
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                result.mat[i][j] = 0; // Initialize cell
                for (int k = 0; k < this->cols; k++)
                {
                    result.mat[i][j] += this->mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }
};

int main()
{
    int r1, c1, r2, c2;

    // Get dimensions for Matrix A
    cout << "Enter rows and columns for Matrix A: ";
    cin >> r1 >> c1;
    Matrix A(r1, c1);
    cout << "Enter elements for Matrix A:\n";
    A.read();

    // Get dimensions for Matrix B
    cout << "\nEnter rows and columns for Matrix B: ";
    cin >> r2 >> c2;
    Matrix B(r2, c2);
    cout << "Enter elements for Matrix B:\n";
    B.read();

    // Multiply matrices using the overloaded * operator
    cout << "\nMultiplying Matrix A and Matrix B..." << endl;
    Matrix C = A * B;

    // Display the final output if multiplication was valid
    if (c1 == r2)
    {
        cout << "\nResultant Matrix C:\n";
        C.print();
    }

    return 0;
}
