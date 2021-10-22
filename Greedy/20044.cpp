#include <iostream>
#include <algorithm>
using namespace std;

int w[10001];
int g[5001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> w[i];
    }
    sort(w, w + 2 * n);
    for (int i = 0; i < n; i++)
    {
        g[i] = w[i] + w[2 * n - 1 - i];
    }
    sort(g, g + n);
    cout << g[0] << '\n';
    return 0;
}