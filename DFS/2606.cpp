#include <iostream>
#include <vector>
using namespace std;
bool visited[101];
vector<int> vec[101];
int v, e, cnt = 0;

void dfs(int cur)
{
    visited[cur] = true;
    cnt++; // if 문 안에 넣으면 다 떨어져있을때 틀림
    for (int i = 0; i < vec[cur].size(); i++)
    {
        int next = vec[cur][i];
        if (!visited[next])
        {
            dfs(next);
        }
    }
}

int main()
{
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(1);
    cout << cnt - 1 << '\n';
    return 0;
}