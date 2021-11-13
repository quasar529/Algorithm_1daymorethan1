// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <vector>
// using namespace std;

// int map[52][52];
// int dx[4] = {-1, 0, 1, 0};
// int dy[4] = {0, -1, 0, 1};

// vector<vector<int>> vec;
// vector<bool> visited;
// int M, N, K;

// void dfs(int cur)
// {
//     visited[cur] = true;
//     for (int next : vec[cur])
//     {
//         if (!visited[next])
//             dfs(next);
//     }
// }
// int dfsAll()
// {
//     int components = 0;
//     fill(visited.begin(), visited.end(), false);
//     for (int i = 0; i < M; i++)
//     {
//         if (!visited[i])
//         {
//             dfs(i);
//             components++;
//         }
//     }
//     return components;
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         cin >> M >> N >> K;
//         vec.resize(M);
//         visited.resize(M);
//         while (K--)
//         {
//             int a, b;
//             cin >> a >> b;
//             vec[a].push_back(b);
//             vec[b].push_back(a);
//         }
//         for (int i = 0; i < N; i++)
//         {
//         }
//         fill(visited.begin(), visited.end(), false);
//         int components = dfsAll();
//         cout << components << '\n';
//     }
//     return 0;
// }
#include <iostream>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;
bool visited[51][51] = {
    false,
};
int map[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int M, N, K;
void dfs(ii cur)
{
    visited[cur.first][cur.second] = true;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!map[i][j])
                continue;
            if (visited[i][j])
                continue;
            dfs(ii(i, j));
        }
    }
}
int dfsAll()
{
    int components = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!map[i][j])
            {
                continue;
            }
            if (visited[i][j])
                continue;
            dfs(ii(i, j));
            components++;
        }
    }
    return components;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--)
    {
        M, N, K = 0;
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++)
        {
            int a, b;
            cin >> a >> b;
            map[a][b] = 1;
        }
        cout << dfsAll() << '\n';
    }
    return 0;
}