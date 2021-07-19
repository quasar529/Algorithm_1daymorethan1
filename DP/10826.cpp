#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string sum(string str1, string str2)
{
    bool carry = false;
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
        carry = false;

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
int main()
{
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;
    string a = "0", b = "1";
    if (N == 0)
    {
        cout << a << '\n';
    }
    else if (N == 1)
    {
        cout << b << '\n';
    }
    else
    {
        string result;
        for (int i = 0; i <= N - 2; i++)
        {
            result = sum(a, b);
            a = b;
            b = result;
        }
        cout << result << '\n';
    }
    return 0;
}