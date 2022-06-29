#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// 3 5
// 1 2 4
// 2 3 4 5 6

int main()
{
    int n, m;
    cin >> n >> m;
    set<int> arr1;
    set<int> arr2;
    vector<int> ar1;
    vector<int> ar2;
    int num1, num2;
    int count1, count2;
    count1 = n;
    count2 = m;
    for (int a = 0; a < n; a++)
    {
        cin >> num1;
        arr1.insert(num1);
        ar1.push_back(num1);
    }
    for (int a = 0; a < m; a++)
    {
        cin >> num2;
        arr2.insert(num2);
        ar2.push_back(num2);
    }
    for (int a = 0; a < n; a++)
    {
        if (arr2.find(ar1[a]) != arr2.end())
        {
            count1--;
        }
    }
    for (int a = 0; a < m; a++)
    {
        if (arr1.find(ar2[a]) != arr1.end())
        {
            count2--;
        }
    }
    int answer = count1 + count2;
    cout << answer;
}