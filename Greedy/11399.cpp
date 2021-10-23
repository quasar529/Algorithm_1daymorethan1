#include <iostream>
#include <algorithm>
using namespace std;
int P[1001];
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }
    sort(P, P + N);
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += P[i] * (N - i);
    }
    cout << sum << '\n';
    return 0;
}