#include <iostream>
#include <vector>
using namespace std;
long long N, result = 0;
vector<long long> elevens;
int main()
{
    cin >> N;
    long long tmp = N;
    int cnt = 0;
    while (tmp != 0)
    {
        tmp = tmp / 10;
        cnt++;
    }
    elevens.push_back(0);
    elevens.push_back(0);
    elevens.push_back(11);
    for (int i = 3; i <= cnt; i++)
    {
        elevens.push_back(elevens[i - 1] * 10 + 1);
    }
    result += N / 11;
    for (int i = 3; i <= cnt; i += 2)
    {
        result += N / elevens[i];
        result -= N / (elevens[2] * elevens[i]);
        for (int j = i + 2; j < cnt; j += 2)
        {
            result -= N / (elevens[i] * elevens[j]);
            result += N / (elevens[2] * elevens[i] * elevens[j]);
            cout << i << '*' << j << '\n';
        }
    }

    cout << result << '\n';
    return 0;
}