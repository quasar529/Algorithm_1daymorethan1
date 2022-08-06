#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int arr[11] = {
    0,
};
int main()
{
    int N;
    cin >> N;
    vector<int> vec;
    vec.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        vec[i] = i;
        cin >> arr[i];
    }
    int orderArr[11] = {
        0,
    };
    bool flag = false;
    do
    {
        memset(orderArr, 0, sizeof(orderArr));
        for (int i = N; i >= 1; i--)
        {
            for (int j = 1; j < i; j++)
            {
                if (vec[i] < vec[j])
                    orderArr[vec[i]]++;
            }
            // cout << i << ": " << orderArr[i] << '\n';
        }
        // cout << '\n';
        for (int i = 1; i <= N; i++)
        {
            if (arr[i] != orderArr[i])
            {
                flag = false;
                break;
            }
            flag = true;
        }
        if (flag)
        {
            for (int i = 1; i <= N; i++)
            {
                cout << vec[i] << ' ';
            }
            return 0;
        }
    } while (next_permutation(vec.begin(), vec.end()));

    return 0;
}