#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ii = pair<int, int>;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<ii> vec;
        int cnt = 1;
        for (int i = 0; i < N; i++)
        {
            int a, b;
            cin >> a >> b;
            vec.push_back(ii(a, b));
        }
        sort(vec.begin(), vec.end());

        // int interview = vec[0].second;
        // for (int i = 1; i < N; i++)
        // {
        //     if (vec[i].second < interview)
        //     {
        //         cnt++;
        //         interview = vec[i].second;
        //     }
        // }
        vector<ii>::iterator iter = vec.begin();

        for (int i = 1; i < N; i++)
        {
            if ((*iter).second > (*(iter + i)).second)
            {
                cnt++;
                (*iter).second = (*(iter + i)).second;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}