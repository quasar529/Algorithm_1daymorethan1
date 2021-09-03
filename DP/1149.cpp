#include <iostream>

using namespace std;
int N;
int map[1001][3], dp[1001][3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> map[i][0] >> map[i][1] >> map[i][2];
    }
    return 0;
}