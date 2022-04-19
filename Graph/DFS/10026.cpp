#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ii = pair<int, int>;

int N;
int Rmap[101][101];
int Gmap[101][101];
int Bmap[101][101];
int RGmap[101][101];
bool visited[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(ii curr, int map[101][101])
{
    visited[curr.first][curr.second] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = curr.first + dx[i];
        int ny = curr.second + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;
        if (!visited[nx][ny] && map[nx][ny] == 1)
        {
            visited[nx][ny] = true;
            dfs(ii(nx, ny), map);
        }
    }
}

int main()
{
    cin >> N;
    memset(visited, false, sizeof(visited));
    memset(Rmap, 0, sizeof(Rmap));
    memset(Gmap, 0, sizeof(Gmap));
    memset(Bmap, 0, sizeof(Bmap));
    memset(RGmap, 0, sizeof(RGmap));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char temp;
            cin >> temp;
            if (temp == 'R')
            {
                Rmap[j][i] = 1;
                Gmap[j][i] = 0;
                Bmap[j][i] = 0;
                RGmap[j][i] = 1;
            }
            else if (temp == 'G')
            {
                Rmap[j][i] = 0;
                Gmap[j][i] = 1;
                Bmap[j][i] = 0;
                RGmap[j][i] = 1;
            }
            else if (temp == 'B')
            {
                Rmap[j][i] = 0;
                Gmap[j][i] = 0;
                Bmap[j][i] = 1;
                RGmap[j][i] = 0;
            }
        }
    }
    int Rcnt = 0, Gcnt = 0, Bcnt = 0, RGcnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[j][i] && Rmap[j][i] == true)
            {
                dfs(ii(j, i), Rmap);
                Rcnt++;
            }
        }
    }
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[j][i] && Gmap[j][i] == true)
            {
                dfs(ii(j, i), Gmap);
                Gcnt++;
            }
        }
    }
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[j][i] && Bmap[j][i] == true)
            {
                dfs(ii(j, i), Bmap);
                Bcnt++;
            }
        }
    }
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[j][i] && RGmap[j][i] == true)
            {
                dfs(ii(j, i), RGmap);
                RGcnt++;
            }
        }
    }
    cout << Rcnt + Bcnt + Gcnt << ' ' << RGcnt + Bcnt << '\n';
    return 0;
}