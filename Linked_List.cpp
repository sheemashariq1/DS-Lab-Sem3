// Linked list 
// insert_at_beginning(int n), delete_begin(), delete_end(),delete_position(int pos),search(int n),display() Operations.

#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node *head;

public:
    Node()
    {
        head = NULL;
    }
    void insert_at_beginning(int n);
    void delete_begin();
    void delete_end();
    void delete_position(int pos);
    void search(int n);
    void display();
};

void Node::insert_at_beginning(int n)
{
    Node *newNode = new Node();
    newNode->data = n;
    newNode->next = head;
    head = newNode;
}

void Node::delete_begin()
{
    if (head == NULL)
    {
        cout << "\nList is Empty!";
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    cout << "Element deleted from the beginning";
}

void Node::delete_end()
{
    if (head == NULL)
    {
        cout << "\nList is Empty!";
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        cout << "\nThe only element deleted";
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    cout << "Element deleted from the end!";
}

void Node::delete_position(int pos)
{
    if (head == NULL)
    {
        cout << "The list is Empty!";
        return;
    }
    if (pos == 1)
    {
        delete_begin();
        return;
    }
    Node *temp = head;
    Node *prev = NULL;
    for (int i = 1; temp != NULL && i < pos; i++)
    {
        prev = temp;
        temp->next;
    }
    if (temp == NULL)
    {
        cout << "Position does not exist";
        return;
    }
    prev->next = temp->next;
    delete temp;
    cout << "Element deleted!";
}

void Node::search(int n)
{
    Node *temp = head;
    int position = 1;
    int found = 0;
    while (temp != NULL)
    {
        if (temp->data == n)
        {
            cout << "\nValue " << n << " found at position" << position;
            found = 1;
            break;
        }
        temp = temp->next;
        position++;
    }
    if (found == 0)
    {
        cout << "Value not found";
    }
}

void Node::display()
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "The Linked list is empty\n";
        return;
    }
    while (temp != NULL)
    {
        cout << "temp->data" << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{
    Node list;
    int choice, val, pos;
    do
    {
        cout << "===== MENU =====";
        cout << "\n1. Insert at the beginning";
        cout << "\n2. Delete from the beginning";
        cout << "\n3. Delete from the end";
        cout << "\n4. Delete from a particular position";
        cout << "\n5. Seach for an element";
        cout << "\n6. Display the linked list";
        cout << "\n7. Exit";
        cout << "\nEnter you choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> val;
            list.insert_at_beginning(val);
            break;
        case 2:
            list.delete_begin();
            break;
        case 3:
            list.delete_end();
            break;
        case 4:
            cout << "Enter the position to delete: ";
            cin >> pos;
            list.delete_position(pos);
            break;
        case 5:
            cout << "Enter the valur to be searched: ";
            cin >> val;
            list.search(val);
            break;
        case 6:
            list.display();
            break;
        case 7:
            cout << "Exiting the program.....";
            break;
        default:
            cout << "Invalid choice!";
        }
    }while (choice != 7);
}