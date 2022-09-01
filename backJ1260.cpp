#include <queue>
#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int n, m, v;
bool visited[MAX];
int map[MAX][MAX];
queue<int> q;

void reset()
{
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
}

void BFS(int v)
{
    q.push(v);
    visited[v] = true;
    cout << v << " ";

    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (int w = 1; w <= n; w++)
        {
            if (map[v][w] == 1 && visited[w] == 0)
            {
                q.push(w);
                visited[w] = true;
                cout << w << " ";
            }
        }
    }
}

void DFS(int v)
{
    visited[v] = true;
    cout << v << " ";

    for (int i = 1; i <= n; i++)
    {
        if (map[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    reset();
    DFS(v);

    cout << '\n';

    reset();
    BFS(v);

    return 0;
}