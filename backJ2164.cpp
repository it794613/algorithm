#include <set>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> arr1;
    for (int a = 1; a <= n; a++)
    {
        arr1.push(a);
    }
    while (arr1.size() != 1)
    {
        arr1.pop();
        arr1.push(arr1.front());
        arr1.pop();
    }
    cout << arr1.front();
}