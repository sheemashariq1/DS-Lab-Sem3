// Double Ended Circular Queue implementation using Doubly Linked List

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

Node *front = NULL;
Node *rear = NULL;

void insertfront()
{
    Node *temp = new Node();
    cout << "Enter the value to be inserted at the front: ";
    cin >> temp->data;

    if (front == NULL)
    {
        front = rear = temp;
        temp->next = front;
        temp->prev = rear;
    }
    else
    {
        temp->next = front;
        temp->prev = rear;
        front->prev = temp;
        rear->next = temp;
        front = temp;
    }
    cout << "Element Inserted Successfully at Front!" << endl;
}

void insertrear()
{
    Node *temp = new Node();
    cout << "Enter the value to be inserted at the rear: ";
    cin >> temp->data;

    if (rear == NULL)
    {
        front = rear = temp;
        temp->next = front;
        temp->prev = rear;
    }
    else
    {
        temp->prev = rear;
        temp->next = front;
        rear->next = temp;
        front->prev = temp;
        rear = temp;
    }
    cout << "Element Inserted Successfully at Rear!" << endl;
}

void deletefront()
{
    if (front == NULL)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    Node *temp = front;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        front->prev = rear;
        rear->next = front;
    }
    cout << "Deleted element from front: " << temp->data << endl;
    delete temp;
}

void deleterear()
{
    if (rear == NULL)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    Node *temp = rear;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        rear = rear->prev;
        rear->next = front;
        front->prev = rear;
    }
    cout << "Deleted element from rear: " << temp->data << endl;
    delete temp;
}

void display()
{
    if (front == NULL)
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    Node *temp = front;
    cout << "Elements in the queue: ";

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);

    cout << endl;
}

int main()
{
    int choice;
    do
    {
        cout << "\n1. Insert at Front";
        cout << "\n2. Insert at Rear";
        cout << "\n3. Delete from Front";
        cout << "\n4. Delete from Rear";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertfront();
            break;

        case 2:
            insertrear();
            break;

        case 3:
            deletefront();
            break;

        case 4:
            deleterear();
            break;

        case 5:
            display();
            break;

        case 6:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 6);
    return 0;
}
