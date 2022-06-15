#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> result;
    vector<int> same;

    int n = 0;
    for (int a = 0; a < arr.size(); a++)
    {
    }
    return result;
}

int main()
{
    int arr1 = {1,
                1,
                3,
                3,
                0,
                1,
                1};
    int answers = {1,
                   3,
                   0,
                   1};
    if (solution(arr1) == answers)
    {
        cout << "success" << endl;
    }
    else
    {
        cout << "error" << endl;
    }
}