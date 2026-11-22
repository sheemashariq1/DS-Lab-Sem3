// Insertion Sort Implementation using Linked List

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void InsertionSort(Node *&head)
{
    Node *sorted = NULL;
    Node *current = head;

    while (current != NULL)
    {
        Node *nextNode = current->next;
        if (sorted == NULL || sorted->data >= current->data)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            Node *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = nextNode;
    }
    head = sorted;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Enter element: ";
        cin >> value;
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    InsertionSort(head);

    cout << "Sorted Linked List: ";
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}