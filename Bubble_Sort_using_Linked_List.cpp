// Bubble Sort Implementation using Linked List

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void BubbleSort(Node *head, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        Node *current = head;
        Node *nextNode = current->next;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (current->data > nextNode->data)
            {
                int temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
            current = nextNode;
            nextNode = nextNode->next;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
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
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Bubble Sort functionfor Linked List
    BubbleSort(head, n);

    // Sorted Elements
    cout << "Sorted elements: ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}