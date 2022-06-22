#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int compare(char a, char b)
{
    return a > b;
}

int main()
{
    string n;
    cin >> n;
    int ab = n.length();
    vector<char> vec(ab);
    for (int a = 0; a < n.length(); a++)
    {
        vec[a] = n[a];
    }
    sort(vec.begin(), vec.end(), compare);
    for (int b = 0; b < vec.size(); b++)
    {
        cout << vec[b];
    }
}