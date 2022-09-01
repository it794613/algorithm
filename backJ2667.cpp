#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 26
using namespace std;

typedef struct coord
{
    int x;
    int y;
} coord;

queue<coord> q;
int result1 = 0;
vector<int> result;
bool visited[MAX][MAX];
int map[MAX][MAX] = {
    0,
};
int n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(coord A)
{
    q.push(A);
    visited[A.y][A.x] = true;
    int number = 0;
    while (!q.empty())
    {
        coord temp = q.front();
        q.pop();
        number++;
        for (int a = 0; a < 4; a++)
        {
            coord next;
            next.y = temp.y + dy[a];
            next.x = temp.x + dx[a];
            if (next.y >= 0 && next.y < n && next.x >= 0 && next.x < n && visited[next.y][next.x] == false && map[next.y][next.x] == 1)
            {
                q.push(next);
                visited[next.y][next.x] = true;
            }
        }
    }
    return number;
}

int main()
{
    cin >> n;
    int res = 0;
    for (int a = 0; a < n; a++)
    {
        string s;
        cin >> s;
        for (int b = 0; b < n; b++)
        {
            map[a][b] = s[b] - '0';
        }
    }
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            if (map[a][b] == 1 && visited[a][b] == false)
            {
                coord start;
                start.x = b;
                start.y = a;
                result1 = bfs(start);
                res++;
                result.push_back(result1);
            }
        }
    }
    sort(result.begin(), result.end());
    cout << res << '\n';
    for (int a = 0; a < result.size(); a++)
    {
        cout << result[a] << '\n';
    }
}