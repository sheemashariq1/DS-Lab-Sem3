// Define an array class with insert(x, index) and display member functions.
// Therefore,write a program to read n and store the series: 1, 2, 2, 3, 4, 4, 5, 6, 6, …, n  in an array object.

#include <bits/stdc++.h>
using namespace std;

class Array
{
private:
    int *arr;
    int capacity;
    int size;

public:
    Array(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    ~Array()
    {
        delete[] arr;
    }

    void insert(int x, int index)
    {
        if (index >= 0 && index < capacity)
        {
            arr[index] = x;
            if (index >= size)
            {
                size = index + 1;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter total number of terms (n): ";
    cin >> n;

    Array obj(n);

    int val = 1;
    int index = 0;

    while (index < n)
    {
        obj.insert(val, index);
        index++;

        if (val % 2 == 0 && index < n)
        {
            obj.insert(val, index);
            index++;
        }
        val++;
    }

    cout << "The stored series is: ";
    obj.display();

    return 0;
}

// if n means the maximum number in the series.

class Array
{
private:
    int *arr;     // Pointer to hold the dynamic array
    int capacity; // Total capacity of the array
    int size;     // Current number of elements stored

public:
    // Constructor to dynamically allocate memory
    Array(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    // Destructor to free the allocated memory
    ~Array()
    {
        delete[] arr;
    }

    // Member function to insert an element at a specific index
    void insert(int x, int index)
    {
        if (index >= 0 && index < capacity)
        {
            arr[index] = x;
            if (index >= size)
            {
                size = index + 1; // Update size to track the farthest element
            }
        }
    }

    // Member function to display the array elements
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter total number of terms (n): ";
    cin >> n;

    // Create a dynamic array object with capacity 'n'
    Array obj(n);

    int current_val = 1;
    int index = 0;

    // Generate the series: 1, 2, 2, 3, 4, 4, 5, 6, 6...
    while (index < n)
    {
        // Step 1: Insert the value once
        obj.insert(current_val, index);
        index++;

        // Step 2: If the value is even, insert it a second time (if space allows)
        if (current_val % 2 == 0 && index < n)
        {
            obj.insert(current_val, index);
            index++;
        }

        // Move to the next number in sequence
        current_val++;
    }

    cout << "The stored series is: ";
    obj.display();
    return 0;
}