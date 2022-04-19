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
        Q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if (nextX < 0 || nextY < 0 || nextX >= w || nextY >= h)
                continue;
            if (map[nextY][nextY] && !visited[nextY][nextX])
            {
                Q.push(ii(nextY, nextX));
                visited[nextY][nextX] = true;
            }
        }
    }
}
void dfs(ii curr)
{
    // visited[curr.second][curr.first] = true;
    for (int i = 0; i < 8; i++)
    {
        int nx = curr.second + dx[i];
        int ny = curr.first + dy[i];
        // cout << "ny,nx=" << ny << nx << '\n';
        if (nx >= 0 && ny >= 0 && nx < w && ny < h)
        {
            if (!visited[ny][nx] && map[ny][nx])
            {
                visited[ny][nx] = true;
                // cout << "ny,nx" << ny << ' ' << nx << '\n';
                dfs(ii(ny, nx));
            }
        }
    }
}
// int dfsAll(ii cur)
// {
//     int components = 0;
//     // cout << "dfsAll" << '\n';
//
//     for (int i = 0; i < cur.second; i++)
//     {
//         for (int j = 0; j < cur.first; j++)
//         {
//             if (!visited[i][j] && map[i][j])
//             {
//                 cout << "(i,j) " << i << j << '\n';
//                 dfs(ii(i, j));
//                 components++;
//             }
//         }
//     }
//     return components;
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // while (1)
    // {
    //     cin >> w >> h;
    //     if (w == 0 && h == 0)
    //         break;
    //     memset(map, 0, sizeof(map));
    //     memset(visited, false, sizeof(visited));
    //     for (int i = 0; i < h; i++)
    //     {
    //         for (int j = 0; j < w; j++)
    //         {
    //             cin >> map[i][j];
    //         }
    //     }
    //     for (int i = 0; i < h; i++)
    //     {
    //         for (int j = 0; j < w; j++)
    //         {
    //             if (map[i][j] && !visited[i][j])
    //             {
    //                 // cout << i << ' ' << j << '\n';
    //                 visited[i][j] = true;
    //                 dfs(ii(i, j));
    //                 components++;
    //             }
    //         }
    //     }
    //     cout << components << '\n';
    //     components = 0;
    // }
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
                    visited[i][j] = true;
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
