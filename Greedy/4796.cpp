#include <iostream>
using namespace std;

int P, L, V;

int main()
{
    int i = 1;
    while (1)
    {
        cin >> L >> P >> V;
        if (P == 0 && L == 0 && V == 0)
        {
            break;
        }
        int x = V / P;
        int mod = V % P;
        int res = x * L;
        if (mod > L)
        {
            res += L;
        }
        else
        {
            res += mod;
        }
        cout << "Case " << i << ": " << res << '\n';
        i++;
    }
    return 0;
}