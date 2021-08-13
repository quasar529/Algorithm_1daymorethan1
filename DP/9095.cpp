#include <iostream>
#include <cstring>
using namespace std;
int dp[12];

int sumof123(int n)
{
    if (n == 1 || n == 2 || n == 3)
        return dp[n];
    if (dp[n] != -1)
        return dp[n];
    dp[n] = sumof123(n - 1) + sumof123(n - 2) + sumof123(n - 3);
    return dp[n];
}

int main()
{
    int T;
    cin >> T;
    memset(dp, -1, sizeof(dp));

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    while (T--)
    {
        int n;
        cin >> n;
        cout << sumof123(n) << '\n';
    }

    return 0;
}
