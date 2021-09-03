#include <iostream>
#include <string>
using namespace std;
int main()
{
    int count = 1;

    // char str[1'000'000];
    // cin.getline(str, 1000000, '\n');

    // for (int i = 0; str[i] != '\n'; i++)
    // {
    //     cout << str[i] << ' ';
    //     if (str[i] == ' ')
    //         count++;
    // }
    // cout << count << '\n';
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            count++;
    }
    // if (str.length() == 1 && count == 1)
    // {
    //     cout << 0 << '\n';
    //     return 0;
    // }
    if (str[0] == ' ')
        count--;
    if (str[str.length() - 1] == ' ')
        count--;
    cout << count << '\n';
    return 0;
}