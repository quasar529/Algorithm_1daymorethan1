#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string BigNumAdd(string str1, string str2)
{
    string result;
    long long sum = 0;

    while (!str1.empty() || !str2.empty() || sum)
    {
        if (!str1.empty())
        {
            sum += str1.back() - '0';
            str1.pop_back();
        }
        if (!str2.empty())
        {
            sum += str2.back() - '0';
            str2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string A, B;
    cin >> A >> B;

    cout << BigNumAdd(A, B) << '\n';
    return 0;
}