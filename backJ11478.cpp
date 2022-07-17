#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

string n;
set<string> arr1;
vector<string> temp;

int main()
{
    cin >> n;
    for (int a = 0; a < n.length(); a++)
    {
        for (int b = 1; b < n.length() - a + 1; b++)
        {
            arr1.insert(n.substr(a, b));
        }
    }
    cout << arr1.size();
}