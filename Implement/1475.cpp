#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <algorithm>
using namespace std;
int arr[10] = {
    0,
};
int main()
{
    string N;
    cin >> N;
    vector<char> vec;
    for (int i = 0; i < N.length(); i++)
    {
        int tmp = N[i] - '0';
        if (tmp == 9)
        {
            arr[6]++;
        }
        else
        {
            arr[tmp]++;
        }
        // if (N.find(N[i], i + 1) != string::npos)
        // {
        //     if (N[i] == '6' || N[i] == '9')
        //     {
        //         tmp.push_back(N[i] - '0');
        //         if (tmp.size() % 2 == 0)
        //         {
        //             answer++;
        //         }
        //         else
        //         {
        //             continue;
        //         }
        //     }
        //     else
        //     {
        //         answer++;
        //     }
        // }
        // else
        // {
        //     continue;
        // }
        // char tmp = N[i];
        // N[i] = ' ';
        // cout << N << ' ';
        // if (N.find(tmp) != string::npos)
        // {
        //     if (tmp == '6' || tmp == '9')
        //     {
        //         vec.push_back(tmp);
        //         if (vec.size() % 2 == 0)
        //         {
        //             answer++;
        //         }
        //         else
        //         {
        //             continue;
        //         }
        //     }
        //     else
        //     {
        //         answer++;
        //     }
        // }
        // N[i] = tmp;
        // cout << N << '\n';
    }
    arr[6] = (arr[6] + 1) / 2;
    int *answer = max_element(arr, arr + 10);
    cout << *answer << ' ' << answer - arr << '\n';
    return 0;
}