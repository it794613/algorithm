#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second)
    {                               // 첫 좌표가 같을 경우
        return p1.first < p2.first; // 2번째 좌표로 비교
    }
    else
    {
        return p1.second < p2.second;
    }
}

int main()
{
    int n, x, y;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), cmp); // 정렬
    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << '\n';
    }

    return 0;
} // 11min
