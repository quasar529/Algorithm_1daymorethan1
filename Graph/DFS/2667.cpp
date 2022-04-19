#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ii = pair<int, int>;
int map[26][26];
bool visited[26][26] = {
    0,
};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> numOfApartments;
int N, nodes = 1;
void dfs(ii curr)
{
    nodes++;
    visited[curr.first][curr.second] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = curr.first + dx[i];
        int ny = curr.second + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;
        if (map[nx][ny] == 1 && !visited[nx][ny])
        {
            dfs(ii(nx, ny));
        }
    }
}
void dfsAll()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                nodes = 0;
                dfs(ii(i, j));
                numOfApartments.push_back(nodes);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = temp[j] - '0';
        }
    }

    dfsAll();

    sort(numOfApartments.begin(), numOfApartments.end());
    cout << numOfApartments.size() << '\n';
    for (int i = 0; i < numOfApartments.size(); i++)
    {
        cout << numOfApartments[i] << '\n';
    }
    return 0;
}