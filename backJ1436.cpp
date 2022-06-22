#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define Test 1

int main()
{
    int n;
    int count = 0;
    int numbers = 665;
    int temp;
    cin >> n;
    while (count != n)
    {
        numbers++;
        temp = numbers;
        while (temp != 0)
        {
            if (temp % 1000 == 666)
            {
                count++;
                break;
            }
            else
            {
                temp /= 10;
            }
        }
    }
    cout << numbers;
}