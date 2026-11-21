// Implementation of Stack Operations using Linked List

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *top = NULL;

void push()
{
    Node *newNode = new Node();

    cout << "Enter Element: ";
    cin >> newNode->data;
    newNode->next = top;
    top = newNode;
    cout << "Element Successfully Inserted" << endl;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
        return;
    }

    Node *temp = top;
    cout << "Popped element: " << temp->data << endl;
    top = top->next;
    delete temp;
}

void display()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }

    Node *temp = top;
    cout << "Stack elements (top to bottom): ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int choice, value;
    do
    {
        cout << "\n----- Stack using Linked List -----" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 4);
    return 0;
}
