#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long triangle[4];
int main()
{
    long long a, b, c;
    while (1)
    {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;
        triangle[0] = a;
        triangle[1] = b;
        triangle[2] = c;
        sort(triangle, triangle + 3);
        if (pow(triangle[2], 2) == pow(triangle[0], 2) + pow(triangle[1], 2))
        {
            cout << "right" << '\n';
        }
        else
            cout << "wrong" << '\n';
    }

    return 0;
}