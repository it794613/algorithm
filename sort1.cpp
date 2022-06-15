#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands)
{
    vector<int> answer;
    vector<int> temp;
    for (int a = 0; a < commands.size(); a++)
    {
        for (int c = commands[a][0]; c <= commands[a][1]; c++)
        {
            temp.push_back(array[c - 1]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[a][2] - 1]);
        temp.clear();
    }
    return answer;
}

int main()
{
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int> > commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    vector<int> result = {5, 6, 3};

    if (solution(array, commands) != result)
    {
        cout << "error" << endl;
        return 0;
    }
    cout << "success" << endl;
}