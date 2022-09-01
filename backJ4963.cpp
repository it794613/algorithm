#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

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
queue<coord> q;
int w, h;
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

void bfs(coord A)
{
    q.push(A);
    visited[A.y][A.x] = true;
    while (!q.empty())
    {
        coord temp = q.front();
        q.pop();
        for (int a = 0; a < 8; a++)
        {
            coord next;
            next.y = temp.y + dy[a];
            next.x = temp.x + dx[a];
            if (next.y >= 0 && next.y < h && next.x >= 0 && next.x < w && visited[next.y][next.x] == false && map[next.y][next.x] == 1)
            {
                q.push(next);
                visited[next.y][next.x] = true;
            }
        }
    }
}

void reset()
{
    for (int a = 0; a < w; a++)
    {
        for (int b = 0; b < h; b++)
        {
            visited[a][b] = false;
            map[a][b] = 0;
            while (q.empty())
            {
                q.pop();
            }
        }
    }
}

int main()
{
    while (1)
    {
        int cnt = 0;
        cin >> w >> h;
        if (!w && !h)
            break;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
            }
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (!visited[i][j] && map[i][j])
                {
                    coord start;
                    start.x = j;
                    start.y = i;
                    visited[i][j] = 1;
                    bfs(start);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
        memset(visited, 0, sizeof(visited));
    }
}