#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define MAX 9

using namespace std;
// 전형적인 백트레킹 문제이다.
// 백트레킹 유형은 많지가 않으니 해당 코드를 잘 봐둘 필요가 있다.
int arr[MAX] = {
    0,
};
bool visited[MAX] = {
    0,
};
int n, m;

void back(int cnt)
{
    if (cnt == m)
    {
        for (int a = 0; a < m; a++)
        {
            cout << arr[a] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i;
            back(cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    n = 4;
    m = 3;
    back(0);
}