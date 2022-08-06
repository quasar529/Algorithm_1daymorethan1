#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    queue<int> q;
    int N;
    cin >> N;
    while (N--)
    {
        string str;
        cin >> str;
        if (str == "push")
        {
            int tmp;
            cin >> tmp;
            q.push(tmp);
        }
        else if (str == "size")
        {
            cout << q.size() << '\n';
        }
        else if (str == "empty")
        {
            if (q.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (str == "front")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.front() << '\n';
        }
        else if (str == "back")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.back() << '\n';
        }
        else if (str == "pop")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
            {
                cout << q.front() << '\n';
                q.pop();
            }
        }
    }
    return 0;
}

// else
//         {
//             string num = 0;
//             for (int i = 5; i < str.length(); i++)
//             {
//                 num += str[i];
//             }
//             q.push(stoi(num));
//         }