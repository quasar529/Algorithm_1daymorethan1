#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[10] = {
    0,
};
int main()
{
    int N;
    cin >> N;
    for (int i = 1; i < N - 1; i++)
    {
        memset(arr, 0, sizeof(arr));
        int tmp = i, sum = 0;
        sum += tmp;
        while (tmp)
        {
            arr[tmp % 10]++;
            tmp /= 10;
        }
        for (int j = 0; j < 10; j++)
        {
            if (arr[j] > 0)
            {
                while (arr[j])
                {
                    sum += j;
                    arr[j]--;
                }
            }
        }

        if (sum == N)
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}