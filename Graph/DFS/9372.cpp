#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int T, N, M, result = 0;
vector<int> vec[1001];
bool visited[1001];
void dfs(int curr)
{
    visited[curr] = true;
    result++;
    for (int next : vec[curr])
    {
        if (!visited[next])
        {
            dfs(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
        vec->clear();
        memset(visited, false, sizeof(visited));
        result = 0;
        dfs(1);
        cout << result - 1;
        if (T == 0)
            break;
        cout << '\n';
    }
    return 0;
}