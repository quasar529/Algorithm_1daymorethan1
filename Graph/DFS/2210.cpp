#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
using ii = pair<int, int>;

vector<int> digits;
vector<int> results;
int map[5][5] = {
    0,
};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
// int dfs(ii curr)
// {
//     nodes = 1;
//     // visited[curr.first][curr.second];

//         for (int j = 0; j < 4; j++)
//         {
//             int nx = curr.first + dx[j];
//             int ny = curr.second + dy[j];
//             if (nodes != 5)
//             {
//                 nodes += dfs(ii(nx, ny));
//             }
//             digits.push_back(map[nx][ny]);
//         }
//
//     return nodes;
// }
void dfs(ii curr, int cnt)
{
    // if (cnt == 6)
    // {
    //     results.push_back(mapVal);
    //     return;
    // }
    for (int j = 0; j < 4; j++)
    {
        int nx = curr.first + dx[j];
        int ny = curr.second + dy[j];
        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
            continue;
        if (cnt == 6)
        {
            return;
        }
        digits.push_back(map[nx][ny]);

        // dfs(ii(nx, ny), mapVal * 10 + map[nx][ny], cnt + 1);
        dfs(ii(nx, ny), cnt + 1);
    }
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> map[j][i];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int tempRes = 0;

            dfs(ii(j, i), 1);
            for (int k = 0; k < 6; k++)
            {
                tempRes += (digits[k] * pow(10, k));
            }
            results.push_back(tempRes);
            // if (find(results.begin(), results.end(), tempRes) == results.end())
            // {
            //     cout << tempRes << ' ';
            //     results.push_back(tempRes);
            // }
            // digits.clear();
        }
    }
    sort(results.begin(), results.end());
    results.erase(unique(results.begin(), results.end()), results.end());

    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << " ";
    }
    cout << results.size() << '\n';
    return 0;
}