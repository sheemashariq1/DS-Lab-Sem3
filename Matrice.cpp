// Read and multiply two matrices using pointers.

#include <bits/stdc++.h>
using namespace std;

void readMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

int **multiplyMatrices(int **matrixA, int **matrixB, int rowsA, int colsA, int colsB)
{
    int **result = new int *[rowsA];
    for (int i = 0; i < rowsA; i++)
    {
        result[i] = new int[colsB];
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}

int main()
{
    int rowsA, colsA, rowsB, colsB;
    cout << "Enter the number of rows and columns for Matrix A: ";
    cin >> rowsA >> colsA;
    cout << "Enter the number of rows and columns for Matrix B: ";
    cin >> rowsB >> colsB;

    if (colsA != rowsB)
    {
        cout << "Matrix multiplication is not possible. Number of columns in Matrix A must be equal to number of rows in Matrix B." << endl;
        return 0;
    }

    int **matrixA = new int *[rowsA];
    for (int i = 0; i < rowsA; i++)
    {
        matrixA[i] = new int[colsA];
    }

    int **matrixB = new int *[rowsB];
    for (int i = 0; i < rowsB; i++)
    {
        matrixB[i] = new int[colsB];
    }

    cout << "Enter elements of Matrix A:" << endl;
    readMatrix(matrixA, rowsA, colsA);

    cout << "Enter elements of Matrix B:" << endl;
    readMatrix(matrixB, rowsB, colsB);

    cout << "Matrix A:" << endl;
    printMatrix(matrixA, rowsA, colsA);
    cout << "Matrix B:" << endl;
    printMatrix(matrixB, rowsB, colsB);

    int **result = multiplyMatrices(matrixA, matrixB, rowsA, colsA, colsB);

    cout << "Resultant Matrix after multiplication:" << endl;
    printMatrix(result, rowsA, colsB);

    // Free allocated memory
    for (int i = 0; i < rowsA; i++)
    {
        delete[] matrixA[i];
        delete[] result[i];
    }
    delete[] matrixA;
    delete[] result;

    for (int i = 0; i < rowsB; i++)
    {
        delete[] matrixB[i];
    }
    delete[] matrixB;
    return 0;
}