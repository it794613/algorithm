#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 101

using namespace std;

int n, m, v;
int map[MAX][MAX] = {
    0,
};
bool visited[MAX];
queue<int> q;
int result;
int number = 0;

int bfs(int A)
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
                number++;
            }
        }
    }
    return number;
}

int main()
{
    cin >> n >> m;
    int num1, num2;
    for (int a = 0; a < m; a++)
    {
        cin >> num1 >> num2;
        map[num1][num2] = 1;
        map[num2][num1] = 1;
    }
    result = bfs(1);
    cout << result;
}