#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
using ii = pair<int, int>;
int map[51][51] = {
    0,
};
bool visited[51][51] = {
    0,
};
int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[8] = {0, -1, 0, 1, -1, 1, -1, 1};
int w, h, components = 0;
queue<ii> Q;

void bfs()
{
    while (!Q.empty())
    {
        int y = Q.front().first;
        int x = Q.front().second;
        visited[y][x] = true;
        Q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            // cout << "nextY, nextX : " << nextY << ' ' << nextX << '\n';
            // cout << "map : " << map[nextY][nextX] << '\n';
            if (nextX < 0 || nextY < 0 || nextX > w || nextY > h)
                continue;
            if (map[nextY][nextX] && !visited[nextY][nextX])
            {
                // cout << nextY << ' ' << nextX << '\n';
                Q.push(ii(nextY, nextX));
                visited[nextY][nextX] = true;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
            }
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (map[i][j] && !visited[i][j])
                {
                    Q.push(ii(i, j));
                    // cout << "i,j : " << i << ' ' << j << '\n';
                    bfs();
                    components++;
                }
            }
        }
        cout << components << '\n';
        components = 0;
    }
    return 0;
}
