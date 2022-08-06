// #include <iostream>
// #include <string>
// #include <cstring>
// using namespace std;
// int arr[26] = {
//     0,
// };
// int main()
// {
//     int N;
//     cin >> N;
//     int cnt = 0;
//     while (N--)
//     {
//         bool tag = true;
//         memset(arr, 0, sizeof(arr));
//         string str;
//         cin >> str;
//         for (int i = 0; i < str.length(); i++)
//         {

//             if (arr[str[i] - 'a'] == 0)
//             {
//                 arr[str[i] - 'a']++;
//             }
//             else if (arr[str[i] - 'a'] != 0)
//             {
//                 if (i + 1 == str.length() || str[i] != str[i + 1])
//                 {
//                     tag = false;
//                     arr[str[i] - 'a']++;
//                 }
//                 else
//                 {
//                     arr[str[i] - 'a']++;
//                 }
//             }
//         }
//         // int tmp = 0;
//         // while (tmp < 26)
//         // {
//         //     cout << arr[tmp] << ' ';
//         //     if (tmp % 5 == 0)
//         //         cout << '\n';
//         //     tmp++;
//         // }
//         if (tag)
//             cnt++;
//     }
//     cout << cnt << '\n';
//     return 0;
// }

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        bool tag = true;
        str.erase(unique(str.begin(), str.end()), str.end());
        sort(str.begin(), str.end());
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == str[i + 1])
            {
                tag = false;
                break;
            }
        }
        if (tag)
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}