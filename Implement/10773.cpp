#include <iostream>
#include <stack>

using namespace std;
stack<int> st;
int main()
{
    int K;
    cin >> K;
    while (K--)
    {
        int temp;
        cin >> temp;
        if (temp != 0)
        {
            st.push(temp);
        }
        else if (temp == 0)
        {
            st.pop();
        }
    }
    int sum = 0;
    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    cout << sum << '\n';
    return 0;
}