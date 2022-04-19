// #include <iostream>
// #include <queue>
// #include <cstring>
// using namespace std;
// using ii = pair<int, int>;
// int map[101][101] = {
//     0,
// };
// int tempMap[101][101] = {
//     0,
// };
// queue<ii> Q;

// bool visited[101][101] = {
//     false,
// };
// int dx[4] = {-1, 0, 1, 0};
// int dy[4] = {0, -1, 0, 1};
// int N, components = 0;
// void bfs()
// {
//     while (!Q.empty())
//     {
//         int x = Q.front().first;
//         int y = Q.front().second;
//         cout << "Q front: " << x << ' ' << y << '\n';
//         for (int i = 0; i < 4; i++)
//         {
//             int nextX = x + dx[i];
//             int nextY = y + dy[i];
//             cout << "i: " << i << " nextX, nextY : " << nextX << ' ' << nextY << '\n';

//             Q.pop();
//             if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N)
//                 continue;

//             if (tempMap[nextX][nextY] > 0 && !visited[nextX][nextY])
//             {
//                 Q.push(ii(nextX, nextY));
//                 visited[nextX][nextY] = true;
//                 // cout << "i: " << i << " nextX, nextY : " << nextX << ' ' << nextY << '\n';
//             }
//         }
//     }
// }
// void dfs(ii curr)
// {
//     int x = curr.first;
//     int y = curr.second;
//     // visited[x][y] = true;
//     for (int i = 0; i < 4; i++)
//     {
//         int nextX = x + dx[i];
//         int nextY = y + dy[i];
//         if (nextX >= 0 && nextY >= 0 && nextX < N && nextY < N)
//         {
//             if (tempMap[nextX][nextY] > 0 && !visited[nextX][nextY])
//             {
//                 visited[nextX][nextY] = true;
//                 dfs(ii(nextX, nextY));
//             }
//         }
//     }
// }
// int main()
// {
//     int maxheight = 0;
//     int maxComponents = 0;
//     cin >> N;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             cin >> map[i][j];
//             if (maxheight < map[i][j])
//             {
//                 maxheight = map[i][j];
//             }
//         }
//     }
//     for (int h = 1; h <= maxheight; h++)
//     {
//         cout << "H : " << h << '\n';
//         components = 0;
//         memset(tempMap, 0, sizeof(tempMap));
//         memset(visited, false, sizeof(visited));

//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < N; j++)
//             {
//                 if (map[i][j] - h <= 0)
//                 {
//                     tempMap[i][j] = 0;
//                 }
//                 else
//                 {
//                     tempMap[i][j] = map[i][j] - h;
//                 }
//                 cout << tempMap[i][j] << ' ';
//             }
//             cout << '\n';
//         }

//         for (int x = 0; x < N; x++)
//         {
//             for (int y = 0; y < N; y++)
//             {
//                 if (tempMap[x][y] > 0 && !visited[x][y])
//                 {
//                     // Q.push(ii(x, y));
//                     // bfs();
//                     // cout << "start dfs " << '\n';
//                     visited[x][y] = true;
//                     components++;
//                     dfs(ii(x, y));
//                 }
//             }
//         }
//         cout << "com: " << components << '\n';
//         if (maxComponents < components)
//         {
//             maxComponents = components;
//         }
//     }
//     cout << maxComponents << '\n';

//     return 0;
// }
#include <iostream>
#include <cstring>
using namespace std;
using ii = pair<int, int>;
int map[101][101] = {
    0,
};
int tempMap[101][101] = {
    0,
};
bool visited[101][101] = {
    false,
};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int N, components = 0;
void dfs(ii curr)
{
    int x = curr.first;
    int y = curr.second;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX >= 0 && nextY >= 0 && nextX < N && nextY < N)
        {
            if (tempMap[nextX][nextY] > 0 && !visited[nextX][nextY])
            {
                visited[nextX][nextY] = true;
                dfs(ii(nextX, nextY));
            }
        }
    }
}
int main()
{
    int maxheight = 0;
    int maxComponents = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (maxheight < map[i][j])
            {
                maxheight = map[i][j];
            }
        }
    }
    for (int h = 1; h <= maxheight; h++)
    {
        components = 0;
        memset(tempMap, 0, sizeof(tempMap));
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (map[i][j] - h <= 0)
                {
                    tempMap[i][j] = 0;
                }
                else
                {
                    tempMap[i][j] = map[i][j] - h;
                }
            }
        }

        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                if (tempMap[x][y] > 0 && !visited[x][y])
                {
                    visited[x][y] = true;
                    components++;
                    dfs(ii(x, y));
                }
            }
        }
        if (maxComponents < components)
        {
            maxComponents = components;
        }
    }
    cout << maxComponents << '\n';
    return 0;
}