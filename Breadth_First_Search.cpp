#include <iostream>
using namespace std;

#define MAX 20
int graph[MAX][MAX];
int visited[MAX];
int n;

void BFS(int start)
{
    int queue[MAX];
    int front = 0, rear = -1;
    int v, i;

    queue[++rear] = start;
    visited[start] = 1;

    cout << "BFS Traversal: ";

    while (front <= rear)
    {
        v = queue[front++];
        cout << v << " ";

        for (i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
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

    BFS(start);
    return 0;
}