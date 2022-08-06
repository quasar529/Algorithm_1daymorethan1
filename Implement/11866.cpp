#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> vec, ans;
    for (int i = 1; i <= N; i++)
    {
        vec.push_back(i);
    }
    while (!vec.empty())
    {
        if (vec.size() >= K)
        {
            cout << vec[K - 1] << ', ';
            // ans.push_back(vec[K - 1]);
            vec.erase(vec.begin() + (K - 1));
            for (int i = K - 1; i < vec.size(); i++)
            {
            }
        }
    }

    return 0;
}