#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int T, N, M, result = 0;
vector<int> vec[1001];
vector<bool> visited[1001];
void dfs(int curr)
{
    visited[curr] = true;
    for (int next : vec[curr])
    {
        if (!visited[next])
        {
            result++;
            visited[next] = true;
            dfs(next);
        }
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        while (M--)
        {
            int a, b;
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        dfs(1);
        cout << result << '\n';
    }
    return 0;
}