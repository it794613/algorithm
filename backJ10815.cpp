#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

using namespace std;
#define Test 0

int num1 = 0;
int num2 = 0;
int arr1[500001] = {
    0,
};
int arr2[500001] = {
    0,
};

void binary(int k, int n)
{
    // n은 검색하고자 하는 값,찾는 값의 k는 배열의 길이
    int start_index = 0;
    int end_index = k - 1;
    while (start_index <= end_index)
    {
        int mid_index = (start_index + end_index) / 2;
        if (arr1[mid_index] == n)
        {
            cout << "1 ";
            return;
        }
        else
        {
            if (arr1[mid_index] > n)
            {
                end_index = mid_index - 1;
            }
            else
            {
                start_index = mid_index + 1;
            }
        }
    }
    cout << "0 ";
}

int main()
{
    cin >> num1;
    for (int a = 0; a < num1; a++)
    {
        cin >> arr1[a];
    }
    cin >> num2;
    for (int a = 0; a < num2; a++)
    {
        cin >> arr2[a];
    }
    sort(arr1, arr1 + num1);
    for (int i = 0; i < num2; i++)
    {
        binary(num1, arr2[i]);
    }
}