#include <iostream>
using namespace std;

#define MAX 100

class Node
{
public:
    char data;
    Node *left;
    Node *right;
};

Node *queue[MAX];
int front = 0;
int rear = -1;

Node *createNode(char value)
{
    Node *temp = new Node;

    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void build(Node *r, Node *p)
{
    char ans, value;

    if (r == NULL)
        return;

    cout << "Does left child of " << r->data << " exist? (y/n): ";
    cin >> ans;

    if (ans == 'y' || ans == 'Y')
    {
        cout << "Enter left child of " << r->data << ": ";
        cin >> value;

        r->left = createNode(value);
        build(r->left, r);
    }

    cout << "Does right child of " << r->data << " exist? (y/n): ";
    cin >> ans;

    if (ans == 'y' || ans == 'Y')
    {
        cout << "Enter right child of " << r->data << ": ";
        cin >> value;

        r->right = createNode(value);
        build(r->right, r);
    }
}

int isEmpty(Node *root)
{
    if (root == NULL)
        return 1;
    else
        return 0;
}

int getSize(Node *r)
{
    if (r == NULL)
        return 0;

    return 1 + getSize(r->left) + getSize(r->right);
}

void preOrder(Node *r)
{
    if (r == NULL)
        return;

    cout << r->data << " ";
    preOrder(r->left);
    preOrder(r->right);
}

void inOrder(Node *r)
{
    if (r == NULL)
        return;

    inOrder(r->left);
    cout << r->data << " ";
    inOrder(r->right);
}

void postOrder(Node *r)
{
    if (r == NULL)
        return;

    postOrder(r->left);
    postOrder(r->right);
    cout << r->data << " ";
}

void levelOrder(Node *r)
{
    Node *temp;

    if (r == NULL)
        return;

    front = 0;
    rear = -1;

    rear++;
    queue[rear] = r;

    while (front <= rear)
    {
        temp = queue[front];
        front++;

        cout << temp->data << " ";

        if (temp->left != NULL)
        {
            rear++;
            queue[rear] = temp->left;
        }

        if (temp->right != NULL)
        {
            rear++;
            queue[rear] = temp->right;
        }
    }
}

int height(Node *r)
{
    int lh, rh;

    if (r == NULL)
        return 0;

    lh = height(r->left);
    rh = height(r->right);

    if (lh > rh)
        return lh + 1;
    else
        return rh + 1;
}

Node *search(Node *r, char x)
{
    Node *temp;

    if (r == NULL)
        return NULL;

    if (r->data == x)
        return r;

    temp = search(r->left, x);
    if (temp != NULL)
        return temp;

    return search(r->right, x);
}

Node *getRoot(Node *root)
{
    return root;
}

int main()
{
    Node *root;
    char value;

    cout << "Enter root: ";
    cin >> value;

    root = createNode(value);

    build(root, NULL);

    cout << "\nSize: " << getSize(root);

    cout << "\nPreorder: ";
    preOrder(root);

    cout << "\nInorder: ";
    inOrder(root);

    cout << "\nPostorder: ";
    postOrder(root);

    cout << "\nLevel order: ";
    levelOrder(root);

    cout << "\nHeight: " << height(root);

    cout << "\nEnter value to search: ";
    cin >> value;

    if (search(root, value) != NULL)
        cout << "Value Found";
    else
        cout << "Value Not found";
    return 0;
}