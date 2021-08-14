#include <iostream>
#include <cstring>

using namespace std;

long long dp[1001];
int n;

long long sumof1n2(int n)
{
    if (n == 1 || n == 2 || dp[n] != -1)
        return dp[n];
    dp[n] = (sumof1n2(n - 1) + sumof1n2(n - 2)) % 10007;

    return dp[n];
}

int main()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));

    dp[1] = 1;
    dp[2] = 2;
    cout << sumof1n2(n) << '\n';

    return 0;
}