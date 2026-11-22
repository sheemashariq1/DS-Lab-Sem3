// Write a complete C++ program to define a Person class and sort an array of Person objects in ascending order based on their Body Mass Index (BMI) using Insertion Sort.

// Detailed Requirements:
// 1. Class Definition (Person):
//    Define a Person class containing the following attributes:
//    - name
//    - height in centimeters (cm)
//    - weight in kilograms (kg)

// 2. BMI Calculation:
//    - Calculate the BMI of a person using the formula: BMI = weight / (height * height)
//    - Constraint: Do NOT store the BMI as a member variable inside the Person class. Calculate it dynamically using only the height and weight values of the Person object.

// 3. Operator Overloading:
//    - Overload the stream extraction operator (>>) to read input for a Person object.
//    - Overload the stream insertion operator (<<) to display the details of a Person object.
//    - Overload the less-than operator (<) to compare two Person objects based on their calculated BMI values.

// 4. Sorting Algorithm:
//    - Implement the Insertion Sort function: insertionSort(a[0...n-1], n)
//    - The function must take an array 'a' of 'n' Person objects and sort them in non-decreasing (ascending) order of their BMI using the overloaded '<' operator.

#include <iostream>
using namespace std;

class Person
{
    char name[50];
    double height;
    double weight;
    double getBMI()
    {
        return weight / ((height / 100) * (height / 100));
    }

public:
    int operator<(Person &p)
    {
        return getBMI() < p.getBMI();
    }
    friend istream &operator>>(istream &in, Person &p);
    friend ostream &operator<<(ostream &out, Person &p);
};

istream &operator>>(istream &in, Person &p)
{
    cout << "Enter name: ";
    in >> p.name;
    do
    {
        cout << "Enter height in cm: ";
        in >> p.height;
        if (p.height <= 0)
        {
            cout << "Height must be greater than 0. Please enter again." << endl;
        }
    } while (p.height <= 0);
    do
    {
        cout << "Enter weight in kg: ";
        in >> p.weight;
        if (p.weight <= 0)
        {
            cout << "Weight must be greater than 0. Please enter again." << endl;
        }
    } while (p.weight <= 0);
    return in;
}

ostream &operator<<(ostream &out, Person &p)
{
    out << p.name << "\t" << p.height << " cm\t" << p.weight << " kg\t" << p.getBMI() << endl;
    return out;
}

void insertionSort(Person a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Person key = a[i];
        int j = i - 1;
        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    Person *p;
    int n;
    do
    {
        cout << "Enter number of persons: ";
        cin >> n;
    } while (n < 1);
    p = new Person[n];
    if (p == NULL)
    {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter details for person " << i + 1 << ":" << endl;
        cin >> p[i];
    }
    cout << "Persons before sorting by BMI:" << endl;
    cout << "Name\tHeight\tWeight\tBMI" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << endl;
    }

    insertionSort(p, n);

    cout << "Persons after sorting by BMI (Ascending Order):" << endl;
    cout << "Name\tHeight\tWeight\tBMI" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << endl;
    }
    delete[] p;
    return 0;
}