// #include <iostream>
// using namespace std;
// int N, M;

// bool visited[9] = {
//     0,
// };
// int answer[9];

// void solve(int level)
// {
//     if (level == M)
//     {
//         for (int i = 1; i <= M; i++)
//         {
//             cout << answer[i] << ' ';
//         }
//     }
//     if (!visited[level])
//     {
//         visited[level] = true;
//         answer[level] = level;
//         level++;
//     }
// }

// int main()
// {
//     cin >> N >> M;

//     solve(1);

//     return 0;
// }
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    vector<int> vec;
    vec.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        vec[i] = i;
    }
    do
    {
        vector<int> tmpv;
        for (int k = 1; k <= m; k++)
        {
            tmpv.push_back(vec[k]);
            // cout << vec[k] << ' ';
        }

    } while (next_permutation(vec.begin() + 1, vec.end()));
    return 0;
}