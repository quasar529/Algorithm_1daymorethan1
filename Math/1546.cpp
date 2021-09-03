#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
vector<double> vec;
int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        double temp;
        cin >> temp;
        vec.push_back(temp);
    }
    double maxNum = *max_element(vec.begin(), vec.end());
    double avg;
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = vec[i] / maxNum * 100;
        avg += vec[i];
    }
    avg /= vec.size();
    cout << avg << '\n';
    return 0;
}