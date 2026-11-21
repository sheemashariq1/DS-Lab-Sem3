#include <iostream>
using namespace std;

class LinkedListL
{
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head;
public:
    LinkedListL();
    void insert(int data, int pos);
    int isEmpty();
    int size();
    int del(int pos);
};

LinkedListL::LinkedListL()
{
    head = NULL;
}

void LinkedListL::insert(int data, int pos)
{
    Node *temp = new Node();
    temp->data = data;
    if(pos == 0)
    {
        temp->next = head;
        head = temp;
    }
}

int LinkedListL::isEmpty()
{
    if(head == NULL)
        return 1;
    else
        return 0;
}

int LinkedListL::size()
{
    int count = 0;
    Node *temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int LinkedListL::del(int pos)
{
    Node *temp = head;
    Node *prev = NULL;

    for(int i = 0; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    int value = temp->data;

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    return value;
}

int main()
{
    int n, m = 0;
    cout << "Enter number of elements: ";
    cin >> n;
    int *a = new int[n];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter element: ";
        cin >> a[i];

        if(a[i] > m)
            m = a[i];
    }

    // Create buckets
    LinkedListL *L = new LinkedListL[m+1];

    for(int i = 0; i < n; i++)
    {
        L[a[i]].insert(a[i], 0);
    }

    int i = 0;

    for(int j = 0; j <= m; j++)
    {
        while(L[j].isEmpty() == 0)
        {
            a[i] = L[j].del(L[j].size()-1);
            i++;
        }
    }

    cout << "\nSorted elements: ";

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

