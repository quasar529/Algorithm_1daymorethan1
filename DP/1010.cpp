#include <iostream>

using namespace std;

int dp[31][31];
int combination(int n, int m)
{
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][0] = 1;
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][m];
}

int main()
{
    dp[1][0] = 1;
    dp[1][1] = 1;
    int T;
    int N, M;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        cout << combination(M, N) << '\n';
    }

    return 0;
}