#include <iostream>
using namespace std;

#define MAX 20
int graph[MAX][MAX];
int visited[MAX];
int n;

void DFS(int start)
{
    int stack[MAX];
    int top = -1;
    int v, i;

    stack[++top] = start;
    visited[start] = 1;

    cout << "DFS Traversal: ";

    while (top != -1)
    {
        v = stack[top--];
        cout << v << " ";

        for (i = n - 1; i >= 0; i--)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, start;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    DFS(start);
    return 0;
}