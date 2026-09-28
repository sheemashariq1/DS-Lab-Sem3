// Write a program to implement a stack using an array and perform PUSH and POP operations. 
// • Perform the PUSH operation to insert an element into the stack. 
// • Perform the POP operation to remove an element from the stack. 
// • Display the elements of the stack. 
// • Handle stack overflow and stack underflow conditions.

#include <iostream>
using namespace std;

class Stack
{
    int *a;
    int top;
    int n;

public:
    Stack(int size)
    {
        n = size;
        top = -1;
        a = new int[n];
    }

    void push(int value);
    void pop();
    void display();
};

// PUSH operation
void Stack::push(int value)
{
    if(top == n - 1)
    {
        cout << "Stack Overflow\n";
        return;
    }

    top++;
    a[top] = value;

    cout << value << " pushed into stack\n";
}

// POP operation
void Stack::pop()
{
    if(top == -1)
    {
        cout << "Stack Underflow\n";
        return;
    }

    cout << a[top] << " popped from stack\n";
    top--;
}

// Display stack
void Stack::display()
{
    if(top == -1)
    {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Stack elements:\n";

    for(int i = top; i >= 0; i--)
    {
        cout << a[i] << endl;
    }
}

int main()
{
    int n, choice, value;

    cout << "Enter size of stack: ";
    cin >> n;

    Stack s(n);

    do
    {
        cout << "\n1. PUSH";
        cout << "\n2. POP";
        cout << "\n3. DISPLAY";
        cout << "\n4. EXIT";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(choice != 4);

    return 0;
}