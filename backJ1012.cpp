#include <algorithm>
#include <queue>
#include <iostream>
#define MAX 51

using namespace std;

typedef struct coord
{
    int x;
    int y;
} coord;

int map[MAX][MAX] = {
    0,
};
bool visited[MAX][MAX];
int t, n, m, v;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<coord> q;

void bfs(coord A)
{
    q.push(A);
    visited[A.y][A.x] = true;

    while (!q.empty())
    {
        coord temp = q.front();
        q.pop();
        for (int a = 0; a < 4; a++)
        {
            coord next;
            next.x = temp.x + dx[a];
            next.y = temp.y + dy[a];
            if (next.y >= 0 && next.y < n && next.x >= 0 && next.x < m && visited[next.y][next.x] == false && map[next.y][next.x] == 1)
            {
                q.push(next);
                visited[next.y][next.x] = true;
            }
        }
    }
}
void reset()
{
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            map[a][b] = 0;
            visited[a][b] = false;
            while (!q.empty())
            {
                q.pop();
            }
        }
    }
}

int main()
{
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int result = 0;
        cin >> n >> m >> v;
        reset();
        for (int b = 0; b < v; b++)
        {
            int x1, y1;
            cin >> y1 >> x1;
            map[y1][x1] = 1;
        }

        for (int c = 0; c < n; c++)
        {
            for (int d = 0; d < m; d++)
            {
                if (map[c][d] == 1 && visited[c][d] == false)
                {
                    coord start;
                    start.x = d;
                    start.y = c;
                    bfs(start);
                    result++;
                }
            }
        }
        cout << result << "\n";
    }
}