#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

// map 에서 find하면 이터레이터로 반환해줌

// 숫자로 들어오면 > 이름 반환
// 이름 들어오ㅕㅁㄴ > 숫자반환,
// 근데? 키값으로 만약에 포켓몬 이름 넣으면 find 햇을때는 이터레티어 반환됨.

// 숫자 이름.

// 숫자면 > 이름 반환은 그냥 숫자 검색하면됨
// 이름 > 숫자는
// 이름으로 접근 하면 이름이 키값이니까 그냥 반환하면 되고, 숫자로 접근시, 이터레이터로?
// 이름으로 접근시, map.begin()+~~~~ - map.begin() 하면 그 위치아님?
// find 라는 함수를 사용하면, 키 의 이터레이터를 반환하게 된다.
int main()
{
    int n, m;
    cin >> n >> m;
    string st;
    map<string, int> arr1;
    map<int, string> arr2;
    string arr;
    for (int a = 1; a <= n; a++)
    {
        cin >> st;
        arr1.insert(make_pair(st, a));
        arr2.insert(make_pair(a, st));
    }
    for (int a = 0; a < m; a++)
    {
        cin >> arr;
        if (isdigit(arr[0]))
        {
            cout << arr2[stoi(arr)] << "\n";
        }
        else
        {
            cout << arr1[arr] << "\n";
        }
    }
}
