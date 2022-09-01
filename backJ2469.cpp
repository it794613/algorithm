#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX 101

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
int n;
queue<coord> q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(coord A, int li)
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
            if (next.y < n && next.y >= 0 && next.x < n && next.x >= 0 && visited[next.y][next.x] == false && map[next.y][next.x] >= li)
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
        for (int b = 0; b < n; b++)
        {
            visited[a][b] = 0;
        }
    }
}

int main()
{
    cin >> n;
    int limit = n;
    int count = 0;
    vector<int> result;
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            cin >> map[a][b];
        }
    }
    while (1)
    {
        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < n; b++)
            {
                if (visited[a][b] == false && map[a][b] >= limit)
                {
                    coord start;
                    start.x = b;
                    start.y = a;
                    bfs(start, limit);
                    count++;
                }
            }
        }
        if (count == 0)
        {
            break;
        }
        else
        {
            result.push_back(count);
            limit++;
            reset();
        }
    }
    sort(result.begin(), result.end());
    int res = result.size();
    cout << result[res];
}