#include <iostream>
#include <cmath>
using namespace std;

#define MAX 1024

char a[MAX];
int q[MAX];

// Build the binary tree
void build(int i, int n)
{
    char ans;

    if (i >= n)
        return;

    if (i == 0)
        cout << "Enter root: ";
    else if (i % 2 == 1)
        cout << "Enter left child of " << a[(i - 1) / 2] << ": ";
    else
        cout << "Enter right child of " << a[(i - 1) / 2] << ": ";
    cin >> a[i];

    cout << "Does left child of " << a[i] << " exist? (y/n): ";
    cin >> ans;

    if (ans == 'y' || ans == 'Y')
        build(2 * i + 1, n);

    cout << "Does right child of " << a[i] << " exist? (y/n): ";
    cin >> ans;

    if (ans == 'y' || ans == 'Y')
        build(2 * i + 2, n);
}

// Check whether tree is empty
int isEmpty()
{
    if (a[0] == '\0')
        return 1;
    else
        return 0;
}

// Count number of nodes
int size(int n)
{
    int i, count = 0;

    for (i = 0; i < n; i++)
    {
        if (a[i] != '\0')
            count++;
    }

    return count;
}

// Preorder: Root, Left, Right
void preOrder(int i, int n)
{
    if (i >= n || a[i] == '\0')
        return;

    cout << a[i] << " ";
    preOrder(2 * i + 1, n);
    preOrder(2 * i + 2, n);
}

// Inorder: Left, Root, Right
void inOrder(int i, int n)
{
    if (i >= n || a[i] == '\0')
        return;

    inOrder(2 * i + 1, n);
    cout << a[i] << " ";
    inOrder(2 * i + 2, n);
}

// Postorder: Left, Right, Root
void postOrder(int i, int n)
{
    if (i >= n || a[i] == '\0')
        return;

    postOrder(2 * i + 1, n);
    postOrder(2 * i + 2, n);
    cout << a[i] << " ";
}

// Level order traversal using array queue
void levelOrder(int n)
{
    int front = 0, rear = 0;
    int i, left, right;

    if (isEmpty())
        return;

    q[rear] = 0;
    rear++;

    while (front < rear)
    {
        i = q[front];
        front++;

        cout << a[i] << " ";

        left = 2 * i + 1;
        right = 2 * i + 2;

        if (left < n && a[left] != '\0')
        {
            q[rear] = left;
            rear++;
        }

        if (right < n && a[right] != '\0')
        {
            q[rear] = right;
            rear++;
        }
    }
}

// Calculate height of tree in terms of number of nodes
int height(int i, int n)
{
    int leftHeight, rightHeight;

    if (i >= n || a[i] == '\0')
        return 0;

    leftHeight = height(2 * i + 1, n);
    rightHeight = height(2 * i + 2, n);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

// Search for value
int search(char x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int h, n, i;
    char x;
    int result;

    cout << "Enter height capacity h (maximum 10): ";
    cin >> h;

    if (h <= 0 || h > 10)
    {
        cout << "Invalid height capacity.";
        return 0;
    }

    n=pow(2, h) - 1;

    for (i = 0; i < n; i++)
        a[i] = '\0';

    build(0, n);

    cout << "\nTree size: " << size(n);

    cout << "\nPreorder: ";
    preOrder(0, n);

    cout << "\nInorder: ";
    inOrder(0, n);

    cout << "\nPostorder: ";
    postOrder(0, n);

    cout << "\nLevel order: ";
    levelOrder(n);

    cout << "\nActual tree height: " << height(0, n);

    cout << "\nEnter value to search: ";
    cin >> x;

    result = search(x, n);

    if (result == -1)
        cout << x << " not found.";
    else
        cout << x << " found at array index " << result << ".";

    return 0;
}