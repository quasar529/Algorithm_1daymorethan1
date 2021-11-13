#include <iostream>
#include <algorithm>
using namespace std;

int pipe[1001];
bool tape[1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, L;
    cin >> N >> L;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> pipe[i];
    }
    sort(pipe, pipe + N);

    for (int i = 0; i < N; i++)
    {
        if (!tape[pipe[i]])
        {
            for (int j = pipe[i]; j < min(pipe[i] + L, 1001); j++)
            {
                tape[j] = true;
            }
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}