#include <iostream>
using namespace std;
int N, M;

bool visited[9] = {
    0,
};
int answer[9];

void solve(int level)
{
    if (level == M)
    {
        for (int i = 1; i <= M; i++)
        {
            cout << answer[i] << ' ';
        }
    }
    if (!visited[level])
    {
        visited[level] = true;
        answer[level] = level;
        level++;
    }
}

int main()
{
    cin >> N >> M;

    solve(1);

    return 0;
}