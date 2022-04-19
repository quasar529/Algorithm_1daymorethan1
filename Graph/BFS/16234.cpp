#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;
using ii = pair<int, int>;
int N, L, R;
queue<ii> Q;
int populationMap[51][51];
bool visited[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs()
{
    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        visited[x][y] = true;
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = Q.front().first + dx[i];
            int ny = Q.front().second + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
            // L이상 R 이하
            int gap = abs(populationMap[x][y] - populationMap[nx][ny]);
            if (gap >= L && gap <= R)
            {
            }
        }
    }
}

int main()
{
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> populationMap[j][i];
        }
    }
    int cnt = 0;
}