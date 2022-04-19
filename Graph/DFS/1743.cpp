#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;
int N, M, K, nodes = 0;
int map[101][101];
bool visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> garbages;
void dfs(ii curr)
{
    visited[curr.first][curr.second] = true;
    nodes++;

    for (int i = 0; i < 4; i++)
    {
        int nx = curr.first + dx[i];
        int ny = curr.second + dy[i];
        if (nx <= 0 || ny <= 0 || nx > N || ny > M)
            continue;
        if (!visited[nx][ny] && map[nx][ny])
        {

            dfs(ii(nx, ny));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++)
    {
        int r, c;
        cin >> r >> c;
        map[r][c] = 1;
    }
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= M; j++)
    //     {
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // memset(visited, false, sizeof(visited));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (!visited[i][j] && map[i][j])
            {
                nodes = 0;
                dfs(ii(j, i));
            }
        }
        garbages.push_back(nodes);
    }
    sort(garbages.begin(), garbages.end(), greater<>());
    cout << garbages[0] << '\n';
    return 0;
}