#include <iostream>
#include <algorithm>
#include <cstring>
#define NMAX 100'000
int N, value[2][NMAX], dp[NMAX][3];
using namespace std;
int sticker(int c, int status)
{
    if (c == N)
        return 0;
    if (dp[c][status] != -1)
        return dp[c][status];

    int result = sticker(c + 1, 0);

    if (status != 1)
        result = max(result, sticker(c + 1, 1) + value[0][c]);
    if (status != 2)
        result = max(result, sticker(c + 1, 2) + value[1][c]);

    dp[c][status] = result;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> N;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> value[i][j];
            }
        }
        cout << sticker(0, 0) << '\n';
    }
    return 0;
}