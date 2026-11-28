#include <iostream>
using namespace std;

int main()
{
    int *a, n, i, j, temp, key;
    int low, high, mid, found = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    a = new int[n];
    cout << "Enter array elements:\n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Bubble Sort
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Display sorted array
    cout << "\nSorted array:\n";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    // Binary Search
    cout << "\n\nEnter element to search: ";
    cin >> key;

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
        {
            found = 1;
            break;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (found == 1)
    {
        cout << "Element found at position: " << mid + 1;
    }
    else
    {
        cout << "Element not found.";
    }
    delete[] a;
    return 0;
}