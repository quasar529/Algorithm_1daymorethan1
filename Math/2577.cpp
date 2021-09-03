#include <iostream>
#include <string>
using namespace std;

int digitCount[10] = {
    0,
};

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int result = A * B * C;

    string str = to_string(result);
    for (int i = 0; i < str.length(); i++)
    {
        switch (str[i])
        {
        case '0':
            digitCount[0]++;
            break;
        case '1':
            digitCount[1]++;
            break;
        case '2':
            digitCount[2]++;
            break;
        case '3':
            digitCount[3]++;
            break;
        case '4':
            digitCount[4]++;
            break;
        case '5':
            digitCount[5]++;
            break;
        case '6':
            digitCount[6]++;
            break;
        case '7':
            digitCount[7]++;
            break;
        case '8':
            digitCount[8]++;
            break;
        case '9':
            digitCount[9]++;
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << digitCount[i] << '\n';
    }
    return 0;
}