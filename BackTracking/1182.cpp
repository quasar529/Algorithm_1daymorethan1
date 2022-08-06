#include <iostream>
#include <vector>

using namespace std;
int n, s, val[20];
int cnt = 0, cursum = 0;
void dfs(int cur)
{
    if (cur == n)
        return;
    if (cursum + val[cur] == s)
        cnt++;
    dfs(cur + 1);

    cursum += val[cur];
    dfs(cur + 1);

    cursum -= val[cur];
}

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    dfs(0);
    cout << cnt << '\n';
    return 0;
}