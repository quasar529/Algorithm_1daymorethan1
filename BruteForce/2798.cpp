#include <iostream>
#include <cstdlib>
using namespace std;
int arr[101] = {
    0,
};
int main()
{
    int N, M, result = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                int temp = arr[i] + arr[j] + arr[k];
                if (M - temp < M - result && temp <= M)
                {
                    result = temp;
                }
            }
        }
    }
    cout << result << '\n';
    return 0;
}