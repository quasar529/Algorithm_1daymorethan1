#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    vector<char> tmp;
    bool tag = false;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            cout << ' ';
            continue;
        }

        if (s[i] == '<')
        {
            tag = true;
        }
        else if (s[i] == '>')
        {
            tag = false;
            cout << '>';
            continue;
        }

        if (tag)
        {
            cout << s[i];
            continue;
        }

        if (s[i + 1] != '<' && s[i + 1] != ' ' && (i + 1) != s.length())
        {
            tmp.push_back(s[i]);
            // cout << s[i + 1] << '\n';
            //  cout << tmp.back() << " ";
            //   cout << i + 1 << ' ' << s.length();
        }
        else
        {
            tmp.push_back(s[i]);
            int lenoftmp = tmp.size() - 1;
            for (int i = lenoftmp; i >= 0; i--)
            {
                cout << tmp[i];
            }
            tmp.erase(tmp.begin(), tmp.end());
        }
    }
    return 0;
}