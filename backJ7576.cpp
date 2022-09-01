#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 101

using namespace std;

bool visited[MAX][MAX];
int map[MAX][MAX] = {
    0,
};
int n, m;
queue<pair<int, int>> q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void outmap()
{
    for (int a = 0; a < m; a++)
    {
        cout << "\n";
        for (int b = 0; b < n; b++)
        {
            cout << map[a][b];
        }
    }
    cout << "\n";
}

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        visited[y][x] = true;
        q.pop();
        for (int a = 0; a < 4; a++)
        {
            int next_y = y + dy[a];
            int next_x = x + dx[a];
            if (next_y >= 0 && next_y < m && next_x >= 0 && next_x < n && visited[next_y][next_x] == false && map[next_y][next_x] == 0)
            {
                map[next_y][next_x] = map[y][x] + 1;
                q.push(make_pair(next_y, next_x));
                visited[next_y][next_x] = true;
            }
        }
        outmap();
    }
}

int main()
{
    cin >> n >> m;
    for (int a = 0; a < m; a++)
    {
        for (int b = 0; b < n; b++)
        {
            cin >> map[a][b];
        }
    }
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            if (visited[a][b] == false && map[a][b] == 1)
            {
                int x = b;
                int y = a;
                q.push(make_pair(y, x));
            }
        }
    }
    bfs();
    int max = 0;
    for (int a = 0; a < m; a++)
    {
        for (int b = 0; b < n; b++)
        {
            if (map[a][b] == 0)
            {
                cout << -1;
            }
            if (map[a][b] != 0 && map[a][b] != -1)
            {
                if (max < map[a][b])
                {
                    max = map[a][b];
                }
            }
        }
    }
    cout << max;
    return 0;
}