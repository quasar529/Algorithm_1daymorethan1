#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;
vector<int> vec;
int M, N, K;
int map[101][101] = {
    0,
};
bool visited[101][101] = {
    false,
};
int nodes = 0, components = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int dfs(ii curr)
{
    int nodes = 1;
    visited[curr.first][curr.second] = true;
    for (int i = 0; i < 4; i++)
    {
        int nextX = curr.first + dx[i];
        int nextY = curr.second + dy[i];
        if (nextX < 0 || nextY < 0 || nextX > N || nextY > M)
            continue;
        if (!visited[nextX][nextY] && map[nextX][nextY])
        {
            nodes += dfs(ii(nextX, nextY));
        }
    }
    return nodes;
}

int main()
{
    cin >> M >> N >> K;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            map[j][i] = 1;
        }
    }
    while (K--)
    {
        int xld, yld, xru, yru;
        cin >> xld >> yld >> xru >> yru;
        int xlen = xru - xld;
        int ylen = yru - yld;

        for (int i = 0; i < ylen; i++)
        {
            for (int j = 0; j < xlen; j++)
            {
                map[xld + j][yld + i] = 0;
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[j][i] && map[j][i])
            {
                vec.push_back(dfs(ii(j, i)));
                components++;
            }
        }
    }
    cout << components << '\n';
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ' ';
    }
}