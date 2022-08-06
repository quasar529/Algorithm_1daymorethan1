#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <typeinfo>
using namespace std;

stack<int> st;
int main()
{
    string str;
    cin >> str;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    stack<int> iswrong;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[')
        {
            iswrong.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (iswrong.top() == '[')
            {
                cout << 0 << '\n';
                return 0;
            }
        }
        else if (str[i] == ']')
        {
            if (iswrong.top() == '(')
            {
                cout << 0 << '\n';
                return 0;
            }
        }
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else
        {
            if (str[i] == ')')
            {
                if (st.top() == '(')
                {
                    st.pop();
                    st.push(2);
                }
                else if (typeid(st.top()).name() == typeid(int).name())
                {
                    int sum = 0;
                    while (st.top() != '(')
                    {
                        sum += st.top();
                        st.pop();
                    }
                    st.push(2 * sum);
                }
            }
            else if (str[i] == ']')
            {
                if (st.top() == '[')
                {
                    st.pop();
                    st.push(3);
                }
                else if (typeid(st.top()).name() == typeid(int).name())
                {
                    int sum = 0;
                    while (st.top() != '[')
                    {
                        sum += st.top();
                        st.pop();
                    }
                    st.push(3 * sum);
                }
            }
        }
    }
    int result = 0;
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    cout << result << '\n';
    return 0;
}
