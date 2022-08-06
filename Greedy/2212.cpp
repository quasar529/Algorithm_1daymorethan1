#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[10001];
int gap[5001];
int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    for (int i = 0; i < N - 1; i++)
    {
        gap[i] = arr[i + 1] - arr[i];
    }
    sort(gap, gap + N - 1); //,
    // for (int i = 0; i < N - 1; i++)
    // {
    //     cout << (gap[i]) << ' ';
    // }

    int sum = 0;
    for (int i = 0; i < K; i++)
    {
        sum += gap[i];
    }
    cout << sum << '\n';
    return 0;
}