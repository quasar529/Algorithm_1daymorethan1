#include <iostream>

using namespace std;
#define TEST   \
    int tt;    \
    cin >> tt; \
    while (tt--)
#define all(v) (v).begin(), (v).end()
#define loop(e, v) for (auto &(e) : (v))
#define mem(v, e) memset((v), (e), sizeof(v))
#define _unique(v) (v).erase(unique((v).begin(), (v).end()), (v).end())
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define tii tuple<int, int, int>
#define tll tuple<ll, ll, ll>
#define xx first
#define yy second
#define ll long long
#define ld long double
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
const int MAX = 100'005;
const int INF = 1e9 + 1;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;

int a[MAX], b[MAX], c[MAX], d[MAX];
int num[MAX];

int main()
{
    FASTIO
    int N;
    cin >> N;
    string s;
    cin >> s;
    s = " " + s;
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        a[i] = a[i - 1], b[i] = b[i - 1], c[i] = c[i - 1], d[i] = d[i - 1];
        num[i] = num[i - 1];
        if (s[i] == 'T')
            a[i]++;
        else if (s[i] == 'G')
            b[i]++;
        else if (s[i] == 'F')
            c[i]++;
        else
            d[i]++;
        if (a[i] % 3 == 0 && b[i] % 3 == 0 && c[i] % 3 == 0 && d[i] % 3 == 0 && a[i] >= 3 && b[i] >= 3 && c[i] >= 3 && d[i] >= 3)
            num[i]++;
    }
    for (int i = 3; i <= N; i += 3)
    {
        if (a[i] % 3 == 0 && b[i] % 3 == 0 && c[i] % 3 == 0 && d[i] % 3 == 0 && a[i] >= 3 && b[i] >= 3 && c[i] >= 3 && d[i] >= 3)
            ans += num[i];
    }
    cout << ans;
}
