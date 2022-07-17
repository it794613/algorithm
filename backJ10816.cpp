#include <set>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    int number1, number2;
    vector<int> arr1;

    for (int a = 0; a < n; a++)
    {
        cin >> number1;
        arr1.push_back(number1);
    }
    sort(arr1.begin(), arr1.end());
    cin >> m;
    for (int a = 0; a < m; a++)
    {
        cin >> number2;
        auto upper = upper_bound(arr1.begin(), arr1.end(), number2);
        auto lower = lower_bound(arr1.begin(), arr1.end(), number2);
        cout << upper - lower << " ";
    }
}