#include <iostream>
#include <string>
using namespace std;
//65-90
int cnt[100] = {
    0,
};

int main()
{
    string str;
    cin >> str;

    for (char c : str)
    {
        if ('a' <= c)
        {
            c = c - 32;
        }
        cnt[c]++;
    }
    int maxCnt = 0;
    char c = '?';

    for (int alphabet = 'A'; alphabet <= 'Z'; alphabet++)
    {
        if (cnt[alphabet] > maxCnt)
        {
            maxCnt = cnt[alphabet];
            c = alphabet;
        }
        else if (cnt[alphabet] == maxCnt)
        {
            c = '?';
        }
    }
    cout << c << '\n';
    return 0;
}