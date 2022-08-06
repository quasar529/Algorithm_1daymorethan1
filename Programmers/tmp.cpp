#include <iostream>
#include <string>
using namespace std;

int solution(string s)
{
    bool flag = true;
    if (s.length() == 1)
        return 1;
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - 1 - i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        return 1;
    else
        return -1;
}

int main()
{
    string s;
    cin >> s;
    cout << solution(s);
    return 0;
}