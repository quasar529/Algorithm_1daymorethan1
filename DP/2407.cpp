#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string dp[101][101];

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
        result.push_back((sum % 10) + '0'); //일의자리 가져감
        sum /= 10;                          //carry 가져감
    }
    reverse(result.begin(), result.end());
    return result;
}

string sum(string str1, string str2)
{
    int carry = 0;
    string long_str, short_str;
    //같으면 str1이 long_str
    if (str1.size() < str2.size())
    {
        long_str = str2;
        short_str = str1;
    }
    else
    {
        long_str = str1;
        short_str = str2;
    }

    string result(long_str.size(), '0');

    for (int i = 0; i < result.size(); i++)
    {
        int temp = carry;
        carry = 0;

        if (i < str1.size())
        {
            temp += str1[str1.size() - i - 1] - '0';
        }
        if (i < str2.size())
        {
            temp += str2[str2.size() - i - 1] - '0';
        }

        if (temp >= 10)
        {
            carry = true;
            temp -= 10;
        }
        result[result.size() - i - 1] = temp + '0';
    }

    if (carry)
        result.insert(result.begin(), '1');
    return result;
}
string combination(int n, int r)
{
    if (n == r || r == 0)
        return "1";
    string &result = dp[n][r];
    if (result != "")
        return result;

    result = sum(combination(n - 1, r - 1), combination(n - 1, r));
    return result;
}
int main()
{

    int n, m;
    cin >> n >> m;
    cout << combination(n, m) << '\n';
    return 0;
}