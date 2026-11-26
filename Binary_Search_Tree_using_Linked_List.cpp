#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *root = NULL;

Node *createNode(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Insert a node
Node *insert(Node *r, int value)
{
    if (r == NULL)
        return createNode(value);

    if (value < r->data)
        r->left = insert(r->left, value);
    else if (value > r->data)
        r->right = insert(r->right, value);
    else
        cout << "\nDuplicate value not allowed.";

    return r;
}

// Search a value
Node *search(Node *r, int value)
{
    if (r == NULL || r->data == value)
        return r;
    if (value < r->data)
        return search(r->left, value);
    else
        return search(r->right, value);
}

// Find minimum node
Node *findMin(Node *r)
{
    while (r != NULL && r->left != NULL)
        r = r->left;
    return r;
}

// Delete a node
Node *deleteNode(Node *r, int value)
{
    Node *temp;

    if (r == NULL)
        return NULL;

    if (value < r->data)
        r->left = deleteNode(r->left, value);

    else if (value > r->data)
        r->right = deleteNode(r->right, value);

    else
    {
        // Case 1: No child
        if (r->left == NULL && r->right == NULL)
        {
            delete r;
            return NULL;
        }

        // Case 2: Only right child
        else if (r->left == NULL)
        {
            temp = r->right;
            delete r;
            return temp;
        }

        // Case 2: Only left child
        else if (r->right == NULL)
        {
            temp = r->left;
            delete r;
            return temp;
        }

        // Case 3: Two children
        else
        {
            temp = findMin(r->right);
            r->data = temp->data;
            r->right = deleteNode(r->right, temp->data);
        }
    }

    return r;
}

// Preorder: Root, Left, Right
void preOrder(Node *r)
{
    if (r == NULL)
        return;

    cout << r->data << " ";
    preOrder(r->left);
    preOrder(r->right);
}

// Inorder: Left, Root, Right
void inOrder(Node *r)
{
    if (r == NULL)
        return;

    inOrder(r->left);
    cout << r->data << " ";
    inOrder(r->right);
}

// Postorder: Left, Right, Root
void postOrder(Node *r)
{
    if (r == NULL)
        return;

    postOrder(r->left);
    postOrder(r->right);
    cout << r->data << " ";
}

int main()
{
    int choice, value;
    Node *temp;
    do
    {
        cout << "\n\n--- BINARY SEARCH TREE ---";
        cout << "\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Delete";
        cout << "\n4. Preorder";
        cout << "\n5. Inorder";
        cout << "\n6. Postorder";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to be inserted: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;

            temp = search(root, value);

            if (temp != NULL)
                cout << "Value found.";
            else
                cout << "Value not found.";
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            cout << "Deletion operation completed.";
            break;

        case 4:
            cout << "Preorder: ";
            preOrder(root);
            break;

        case 5:
            cout << "Inorder: ";
            inOrder(root);
            break;

        case 6:
            cout << "Postorder: ";
            postOrder(root);
            break;

        case 7:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice.";
        }
    } while (choice != 7);
    return 0;
}