#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int cN;
    cin >> cN;
    int cnt = 1;
    while (cN != 1)
    {
        if (cN % 2 == 0)
        {
            cN = cN / 2;
        }
        else
        {
            cN = 3 * cN + 1;
        }
        cnt++;
    }
    cout << cnt << '\n';

    return 0;
}