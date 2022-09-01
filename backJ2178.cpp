#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
#include <utility>
#define MAX 101

using namespace std;

typedef struct coord
{
    int x;
    int y;
} coord;

int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX];
int cnt[MAX][MAX] = {
    0,
};
queue<coord> q;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
coord temp;

void bfs(coord A)
{
    q.push(A);
    visited[A.y][A.x] = 1;
    cnt[A.y][A.x] = 1;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        for (int a = 0; a < 4; a++)
        {
            coord next;
            next.x = temp.x + dx[a];
            next.y = temp.y + dy[a];
            if (next.x >= 0 && next.y >= 0 && next.x < m && next.y < n && visited[next.y][next.x] == false && map[next.y][next.x] == 1)
            {
                q.push(next);
                visited[next.y][next.x] = true;
                cnt[next.y][next.x] = cnt[temp.y][temp.x] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int a = 0; a < n; a++)
    {
        string s;
        cin >> s;
        for (int b = 0; b < m; b++)
        {
            map[a][b] = paresInt(s[b]);
        }
    }
    coord start;
    start.x = 0;
    start.y = 0;
    bfs(start);
    cout << cnt[n - 1][m - 1];
    return 0;
}
