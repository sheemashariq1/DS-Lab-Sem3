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

Node *stack[MAX];
int top = -1;

Node *createNode(char value)
{
    Node *temp = new Node;

    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void push(Node *r)
{
    if (top < MAX - 1)
    {
        top++;
        stack[top] = r;
    }
}

Node *pop()
{
    if (top == -1)
        return NULL;

    Node *temp = stack[top];
    top--;

    return temp;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;

    return 0;
}

Node *buildExpressionTree(char postfix[])
{
    int i;
    char ch;
    Node *r, *leftNode, *rightNode;

    top = -1;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if (!isOperator(ch))
        {
            r = createNode(ch);
            push(r);
        }
        else
        {
            rightNode = pop();
            leftNode = pop();

            r = createNode(ch);
            r->left = leftNode;
            r->right = rightNode;

            push(r);
        }
    }

    return pop();
}

void inOrder(Node *r)
{
    if (r == NULL)
        return;

    if (isOperator(r->data))
        cout << "(";

    inOrder(r->left);
    cout << r->data;
    inOrder(r->right);

    if (isOperator(r->data))
        cout << ")";
}

void preOrder(Node *r)
{
    if (r == NULL)
        return;

    cout << r->data << " ";
    preOrder(r->left);
    preOrder(r->right);
}

void postOrder(Node *r)
{
    if (r == NULL)
        return;

    postOrder(r->left);
    postOrder(r->right);
    cout << r->data << " ";
}


// Function to evaluate the expression tree
// It will give correct result only if the value of the operands is a single digit number.
int evaluate(Node *r)
{
    int leftValue, rightValue;

    if (r->left == NULL && r->right == NULL)
        return r->data - '0';

    leftValue = evaluate(r->left);
    rightValue = evaluate(r->right);

    if (r->data == '+')
        return leftValue + rightValue;
    else if (r->data == '-')
        return leftValue - rightValue;
    else if (r->data == '*')
        return leftValue * rightValue;
    else if (r->data == '/')
        return leftValue / rightValue;

    return 0;
}

int main()
{
    char postfix[MAX];
    Node *root;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    root = buildExpressionTree(postfix);

    cout << "\nInorder expression: ";
    inOrder(root);

    cout << "\nPreorder: ";
    preOrder(root);

    cout << "\nPostorder: ";
    postOrder(root);

    cout << "\nResult: " << evaluate(root);
    return 0;
}