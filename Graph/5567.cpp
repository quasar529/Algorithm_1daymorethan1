#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
vector<int> vec[501];
bool friends[501];

int result = 0;
void dfs(int curr)
{
    for (int next : vec[curr])
    {
        friends[next] = true;
    }
    if (curr == 1)
    {
        for (int next : vec[curr])
        {
            dfs(next);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    memset(friends, false, sizeof(friends));
    dfs(1);
    for (int i = 2; i <= n; i++)
    {
        if (friends[i])
            result++;
    }
    cout << result << '\n';
}