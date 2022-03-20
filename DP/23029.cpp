#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100'001;
long long N;
int map[MAX];
int dp[MAX][4];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> map[i];
    }
    dp[1][0] = 0;
    dp[1][1] = map[1];
    dp[1][3] = map[1];
    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = dp[i - 1][3];
        dp[i][1] = dp[i - 1][0] + map[i];
        dp[i][2] = dp[i - 1][1] + (map[i] / 2);
        dp[i][3] = max({dp[i][0], dp[i][1], dp[i][2]});
    }

    cout << dp[N][3] << '\n';
    return 0;
}