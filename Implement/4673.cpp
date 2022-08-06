#include <iostream>

using namespace std;

int main()
{
    int arr[10001] = {
        0,
    };
    for (int i = 1; i <= 10000; i++)
    {
        arr[i] = i;
    }
    arr[2] = arr[4] = arr[6] = arr[8] = arr[10] = arr[12] = arr[14] = arr[16] = arr[18] = 0;
    for (int i = 10; i < 100; i++)
    {
        int temp = i + i / 10 + i % 10;
        arr[temp] = 0;
    }
    for (int i = 100; i < 1000; i++)
    {
        int temp = i + i / 100 + (i % 100 / 10) + i % 10;
        arr[temp] = 0;
    }
    for (int i = 1000; i < 10000; i++)
    {
        int temp = i + i / 1000 + (i % 1000 / 100) + (i % 100 / 10) + i % 10;
        if (temp > 10000)
            continue;
        arr[temp] = 0;
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (arr[i] == 0)
            continue;
        cout << arr[i] << '\n';
    }

    return 0;
} // cout << 1 << '\n'
  //      << 3 << '\n'
  //      << 5 << '\n'
  //      << 7 << '\n'
  //      << 9 << '\n';
  // int n = 20;
  // while (n < 1000)
  // {
  //     cout << n << '\n';
  //     n += 11;
  // }
  // n = 1006;
  // while (n < 10000)
  // {
  //     cout << n << '\n';
  //     n += 11;
  // }