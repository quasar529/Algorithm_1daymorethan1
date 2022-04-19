#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using ii = pair<int, int>;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int map[301][301] = {
    0,
};
int path[301][301] = {
    0,
};
bool visited[301][301] = {
    false,
};
int l, goalx, goaly, nowx, nowy;

queue<ii> Q;
void bfs(ii curr)
{
    visited[curr.first][curr.second] = true;
    Q.push(curr);
    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        if (x == goalx && y == goaly)
            break;
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= l || ny >= l)
                continue;
            if (!visited[nx][ny])
            {
                visited[nx][ny] = true;
                Q.push(ii(nx, ny));
                path[nx][ny] = path[x][y] + 1;
            }
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> l;
        cin >> nowx >> nowy >> goalx >> goaly;
        memset(visited, false, sizeof(visited));
        memset(map, 0, sizeof(map));
        memset(path, 0, sizeof(path));
        while (!Q.empty())
        {
            Q.pop();
        }
        bfs(ii(nowx, nowy));
        cout << path[goalx][goaly] << '\n';
    }
    return 0;
}