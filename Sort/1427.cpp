#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> vec;

    int cnt = 0, i = 1;
    while (N / i != 0)
    {
        if (N / i != 0)
        {
            cnt++;
            i *= 10;
        }
    }
    double where = 0;
    where = pow(10, cnt - 1);
    // where /= 10;
    // cout << "where: " << where << '\n';
    // N%10 = 3  N/10 =214  N /100=21 N/1000 = 2
    for (int i = 0; i < cnt - 1; i++)
    {
        int tmp = N / where;
        vec.push_back(tmp);
        N = N - (where * tmp);
        where /= 10;
    }
    vec.push_back(N % 10);
    sort(vec.begin(), vec.end(), greater<int>());
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i];
    return 0;
}