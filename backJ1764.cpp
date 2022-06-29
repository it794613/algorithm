#include <string>
#include <algorithm>
#include <set>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    set<string> arr1;
    string st1;
    string st2;
    set<string> answer;
    for (int a = 0; a < n; a++)
    {
        cin >> st1;
        arr1.insert(st1);
    }
    for (int a = 0; a < m; a++)
    {
        cin >> st2;
        if (arr1.find(st2) != arr1.end())
        {
            answer.insert(st2);
        }
    }
    cout << answer.size() << "\n";
    for (auto i : answer)
    {
        cout << i << endl;
    }
}