#include <iostream>
using namespace std;
long long N;
int main()
{

    {
        cin >> N;
        if (N % 10 == 0)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}