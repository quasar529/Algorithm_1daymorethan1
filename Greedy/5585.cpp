#include <iostream>
using namespace std;
int main()
{
    int money;
    cin >> money;
    int cnt = 0;
    int changes = 1000 - money;
    int coins[6] = {500, 100, 50, 10, 5, 1};
    int i = 0;
    while (1)
    {
        cnt += changes / coins[i];
        changes = changes % coins[i];
        if (changes == 0)
        {
            break;
        }
        i++;
    }
    cout << cnt << '\n';
    return 0;
}