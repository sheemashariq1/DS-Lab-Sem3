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

void insertAtPosition()
{
    int value, pos;
    cout << "Enter value: ";
    cin >> value;
    cout << "Enter position: ";
    cin >> pos;
    Node *temp = new Node();
    temp->data = value;
    if (pos < 1)
    {
        cout << "Invalid Position";
        delete temp;
        return;
    }

    if (front == NULL)
    {
        if (pos != 1)
        {
            cout << "Invalid Position";
            delete temp;
            return;
        }

        front = rear = temp;
        temp->next = front;
        temp->prev = rear;
        return;
    }

    int count = 1;
    Node *ptr = front;

    while (count < pos - 1 && ptr != rear)
    {
        ptr = ptr->next;
        count++;
    }
    if (pos > count + 1)
    {
        cout << "Invalid Position";
        delete temp;
        return;
    }
    if (pos == 1)
    {
        temp->next = front;
        temp->prev = rear;
        front->prev = temp;
        rear->next = temp;
        front = temp;
    }
    else
    {
        temp->next = ptr->next;
        temp->prev = ptr;
        ptr->next->prev = temp;
        ptr->next = temp;

        if (ptr == rear)
            rear = temp;
    }
    cout << "Element Inserted Successfully!";
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

void deleteAtPosition()
{
    int pos;
    cout << "Enter position: ";
    cin >> pos;
    if (front == NULL)
    {
        cout << "Queue is empty!";
        return;
    }

    if (pos < 1)
    {
        cout << "Invalid Position";
        return;
    }
    Node *temp = front;

    for (int i = 1; i < pos && temp != rear; i++)
    {
        temp = temp->next;
    }

    if (pos > 1 && temp == rear && pos > 1)
    {
        // Check whether requested position exists
        int count = 1;
        Node *ptr = front;

        while (ptr != rear)
        {
            count++;
            ptr = ptr->next;
        }

        if (pos > count)
        {
            cout << "Invalid Position";
            return;
        }
    }

    if (pos == 1 && front == rear)
    {
        front = rear = NULL;
    }
    else if (pos == 1)
    {
        front = front->next;
        front->prev = rear;
        rear->next = front;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        if (temp == rear)
            rear = temp->prev;
    }
    cout << "Deleted element: " << temp->data;
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
        cout << "\n3. Insert at Position";
        cout << "\n4. Delete from Front";
        cout << "\n5. Delete from Rear";
        cout << "\n6. Delete at Position";
        cout << "\n7. Display";
        cout << "\n8. Exit";
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
            insertAtPosition();
            break;

        case 4:
            deletefront();
            break;

        case 5:
            deleterear();
            break;

        case 6:
            deleteAtPosition();
            break;

        case 7:
            display();
            break;

        case 8:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice!";
        }
    } while (choice != 8);
    return 0;
}
