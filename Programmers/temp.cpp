#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;

    for (int i = 0; i < lost.size(); i++)
    {
        vector<int>::iterator lostit = lost.begin();
        if (lostit + i == lost.end())
            break;
        for (int j = 0; j < reserve.size(); j++)
        {
            vector<int>::iterator reserveit = reserve.begin();
            if (reserveit + j == reserve.end())
                break;
            if (lost[i] == reserve[j])
            {

                lost.erase(lostit + i);
                reserve.erase(reserveit + j);
            }
        }
    }

    int dx[3] = {-1, 0, 1};
    int okay = lost.size();
    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (find(reserve.begin(), reserve.end(), (lost[i] + dx[j])) != reserve.end())
            {
                // cout << lost[i] + dx[j] << ' ';
                // lost.erase(lost.begin() + i);
                okay--;
                break;
            }
        }
    }
    // cout << lost[0] << '\n';
    answer = n - okay;
    return answer;
}

int main()
{
    vector<int> lost;
    lost.push_back(2);
    lost.push_back(4);
    vector<int> reserve;
    // reserve.push_back(1);
    reserve.push_back(3);
    // reserve.push_back(5);
    cout << solution(5, lost, reserve) << '\n';
    return 0;
}