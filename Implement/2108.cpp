#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int arr[500001];
int freqarr[8001] = {
    0,
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    int avg, mid, freq, range = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + n);
    avg = round(float(sum) / float(n));
    mid = arr[n / 2];
    if (n != 1)
        range = arr[n - 1] - arr[0];
    else
        range = 0;

    int freqcnt = 1;
    vector<int> freqvec;
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        if (temp < 0)
        {
            freqarr[abs(temp) + 4000]++;
        }
        else
        {
            freqarr[temp]++;
        }
        // for (int j = i + 1; j < n; j++)
        // {
        //     if (arr[i] == arr[j])
        //     {
        //         count++;
        //     }
        // }
        // if (freqcnt <= count)
        // {
        //     freqvec.push_back(temp);
        // }
    }
    int *m = max_element(freqarr, freqarr + 8000);
    for (int i = 0; i < 8001; i++)
    {
        if (freqarr[i] == 0)
            continue;
        if (freqarr[i] == *m)
        {
            if (i > 4000)
            {
                freqvec.push_back(-(i - 4000));
            }
            else
                freqvec.push_back(i);
        }
    }

    sort(freqvec.begin(), freqvec.end());
    if (freqvec.size() > 1)
        freq = freqvec[1];
    else
        freq = freqvec[0];
    cout
        << avg << '\n'
        << mid << '\n'
        << freq << '\n'
        << range << '\n';
    return 0;
}