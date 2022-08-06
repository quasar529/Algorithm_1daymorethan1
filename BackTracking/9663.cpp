// nqueen
#include <iostream>
#include <vector>
using namespace std;
int n;
int solve(int cur, vector<int> col, vector<int> diag1, vector<int> diag2)
{
    if (cur == n)
        return 1;
    int ret = 0;
    for (int j = 0; j < n; j++)
    {
        if (col[j] || diag1[cur + j] || diag2[cur - j + n - 1])
            continue;

        col[j] = 1;
        diag1[cur + j] = 1;
        diag2[cur - j + n - 1] = 1;

        ret += solve(cur + 1, col, diag1, diag2);

        col[j] = 0;
        diag1[cur + j] = 0;
        diag2[cur - j + n - 1] = 0;
    }
    return ret;
}
int main()
{
    cin >> n;
    vector<int> col;
    vector<int> diag1;
    vector<int> diag2;
    col.resize(n);
    diag1.resize(n);
    diag2.resize(n);
    fill(col.begin(), col.end(), 0);
    fill(diag1.begin(), diag1.end(), 0);
    fill(diag2.begin(), diag2.end(), 0);
    cout << solve(0, col, diag1, diag2) << '\n';
    return 0;
}