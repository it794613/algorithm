#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 1001

using namespace std;

int n, m, u, v;
bool visited[MAX];
int map[MAX][MAX] = {
    0,
};
queue<int> q;
int number = 0;

void bfs(int A)
{
    q.push(A);
    visited[A] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int a = 1; a <= n; a++)
        {
            if (map[temp][a] == 1 && visited[a] == false)
            {
                q.push(a);
                visited[a] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int a = 0; a < m; a++)
    {
        cin >> u >> v;
        map[u][v] = 1;
        map[v][u] = 1;
    }
    for (int a = 1; a <= n; a++)
    {
        if (visited[a] == false)
        {
            bfs(a);
            number++;
        }
    }
    cout << number;
}