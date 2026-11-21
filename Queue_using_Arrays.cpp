// Implementation of Queue Operations using Arrays

#include <iostream>
using namespace std;

class Queue
{
    int *a;
    int front;
    int rear;
    int n;

public:
    Queue(int size)
    {
        n = size;
        front = -1;
        rear = -1;
        a = new int[n];
    }

    void enqueue(int value);
    void dequeue();
    void display();
};

// ENQUEUE operation
void Queue::enqueue(int value)
{
    if (rear == n - 1)
    {
        cout << "Queue Overflow\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    a[rear] = value;

    cout << value << " pushed into queue\n";
}

// DEQUEUE operation
void Queue::dequeue()
{
    if (front == -1)
    {
        cout << "Queue Underflow\n";
        return;
    }

    cout << a[front] << " dequeued from queue\n";

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

// Display queue
void Queue::display()
{
    if (front == -1)
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements:\n";
    for (int i = front; i <= rear; i++)
    {
        cout << a[i] << endl;
    }
}

int main()
{
    int n, choice, value;
    cout << "Enter size of queue: ";
    cin >> n;
    Queue q(n);
    do
    {
        cout << "\n1. ENQUEUE";
        cout << "\n2. DEQUEUE";
        cout << "\n3. DISPLAY";
        cout << "\n4. EXIT";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice";
        }
    } while (choice != 4);
    return 0;
}