// Implementation of Queue Operations using Linked List

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void insert()
{
    Node *newNode = new Node();
    cout << "Enter Element: ";
    cin >> newNode->data;
    newNode->next = NULL;
    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Element Successfully Inserted" << endl;
}

void deleteElement()
{
    Node *temp;
    if (front == NULL)
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    else
    {
        temp = front;
        front = front->next;
        cout << "Deleted Element: " << temp->data << endl;
        delete temp;
    }
}

void display()
{
    Node *temp;
    if (front == NULL)
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    else
    {
        temp = front;
        cout << "Queue Elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n-----Queue using Linked List-----" << endl;
        cout << "1. Insert Element" << endl;
        cout << "2. Delete Element" << endl;
        cout << "3. Display Elements" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            deleteElement();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    } while (choice != 4);
    return 0;
}