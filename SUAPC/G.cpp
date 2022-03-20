#include <iostream>
#include <string>
using namespace std;
const int MAX = 100'001;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    string str;
    cin >> str;
    int result = 0;
    for (int i = 3; i <= N; i += 3)
    {
        int T_cnt = 0, G_cnt = 0, F_cnt = 0, P_cnt = 0;
        for (int j = 0; j < N - i; j++)
        {
            for (int k = j;)
        }
        // for (int j = 0; j < j + i && j + i < N; j++)
        // {
        //     if (str[j] == 'T')
        //         T_cnt++;
        //     else if (str[j] == 'G')
        //         G_cnt++;
        //     else if (str[j] == 'F')
        //         F_cnt++;
        //     else if (str[j] == 'P')
        //         P_cnt++;
        //     if (T_cnt % 3 == 0 && G_cnt % 3 == 0 && F_cnt % 3 == 0 && P_cnt % 3 == 0)
        //         result++;
        // }
    }

    cout << result << '\n';
}