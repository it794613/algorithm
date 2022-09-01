#include <iostream>
#include <string>
#include <queue>

#define MAX 101

using namespace std;

typedef struct coord
{
    int x;
    int y;
} coord;

int number2 = 0;
int number = 0;
queue<coord> q;
queue<coord> qq;
bool visited1[MAX][MAX];
bool visited2[MAX][MAX];
char map[MAX][MAX] = {
    0,
};
char map2[MAX][MAX] = {
    0,
};
int n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(coord start)
{
    q.push(start);
    visited1[start.y][start.x] = true;
    while (!q.empty())
    {
        coord temp = q.front();
        q.pop();
        for (int a = 0; a < 4; a++)
        {
            coord next;
            next.x = temp.x + dx[a];
            next.y = temp.y + dy[a];
            if (next.y < n && next.y >= 0 && next.x < n && next.x >= 0 && visited1[next.y][next.x] == false && map[next.y][next.x] == map[temp.y][temp.x])
            {
                q.push(next);
                visited1[next.y][next.x] = true;
            }
        }
    }
}

void bfs_RG(coord start)
{
    qq.push(start);
    visited2[start.y][start.x] = true;
    while (!qq.empty())
    {
        coord temp = qq.front();
        qq.pop();
        for (int a = 0; a < 4; a++)
        {
            coord next;
            next.x = temp.x + dx[a];
            next.y = temp.y + dy[a];
            if (next.y < n && next.y >= 0 && next.x < n && next.x >= 0 && visited2[next.y][next.x] == false)
            {
                if (map2[temp.y][temp.x] == 'B')
                {
                    if (map[next.y][next.x] == 'B')
                    {
                        qq.push(next);
                        visited2[next.y][next.x] = true;
                    }
                }
                else
                {
                    if (map[next.y][next.x] == 'R' || map[next.y][next.x] == 'G')
                    {
                        qq.push(next);
                        visited2[next.y][next.x] = true;
                    }
                }
            }
        }
    }
}

int main()
{
    int res;
    int res2;
    cin >> n;
    for (int a = 0; a < n; a++)
    {
        string A;
        cin >> A;
        for (int b = 0; b < n; b++)
        {
            map[a][b] = A[b];
            map2[a][b] = A[b];
        }
    }
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            if (visited1[a][b] == false)
            {
                coord start;
                start.y = a;
                start.x = b;
                bfs(start);
                number++;
            }
            if (visited2[a][b] == false)
            {
                coord start2;
                start2.x = b;
                start2.y = a;
                bfs_RG(start2);
                number2++;
            }
        }
    }
    cout << number
         << '\n'
         << number2;
}