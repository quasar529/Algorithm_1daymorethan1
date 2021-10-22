#include <iostream>

using namespace std;

long long A, B, V;

int main()
{
    cin >> A >> B >> V;
    if (A == V)
    {
        cout << 1 << '\n';
        return 0;
    }
    long long gap = A - B;
    if ((V - A) % gap == 0)
    {
        cout << (V - A) / gap + 1 << '\n';
        return 0;
    }
    else
    {
        cout << (V - A) / gap + 2 << '\n';
        return 0;
    }
    return 0;
}