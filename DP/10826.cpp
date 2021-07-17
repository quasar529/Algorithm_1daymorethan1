#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
vector<ll> dp;

ll fibo(ll n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    dp[n] = fibo(n - 2) + fibo(n - 1);

    return dp[n];
}

int main()
{
    ll N;
    cin >> N;
    dp.resize(N + 1, -1);
    cout << fibo(N) << '\n';
    return 0;
}