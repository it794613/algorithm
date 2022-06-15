// 백준 7568 부르스포스 문제
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct student
{
    int weight;
    int height;
} student;

int main()
{
    int num;
    cin >> num;
    vector<int> ranking(num, 1);
    vector<student> students(num);
    for (int a = 0; a < num; a++)
    {
        cin >> students[a].height;
        cin >> students[a].weight;
    }
    for (int a = 0; a < num; a++)
    {
        for (int b = 0; b < num; b++)
        {
            if (students[a].height < students[b].height && students[a].weight < students[b].weight)
            {
                ranking[a] += 1;
            }
        }
    }
    for (int a = 0; a < ranking.size(); a++)
    {
        cout << ranking[a] << " ";
    }
}