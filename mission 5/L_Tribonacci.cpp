#include <bits/stdc++.h>
using namespace std;

long long mod;
int len;
vector<int> v;
void solve()
{
    long long n, k;
    cin >> n >> k;
    bool full = (n > 24);
    int tk = k;
    n--;
    n %= len;
    // if (!n)
    //     n = len;
    string s = "";
    int x = v[n];
    while (k-- && x)
    {
        s += x % 10 + '0';
        x /= 10;
    }
    if (full)
        while (s.size() < tk)
            s += '0';
    reverse(s.begin(), s.end());
    cout << s << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    int md = 1000000;
    int a = 1, b = 2, c = 3;
    len = 3;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    while (1)
    {
        int d = (a + b + c);
        if (d > md)
            d = d % md + md;
        a = b;
        b = c;
        c = d;
        if (a % md == 1 && b % md == 2 && c % md == 3)
            break;
        v.push_back(d);
        len++;
    }
    // for (int i = 0; i < 70; i++)
    //     cout << i << " -> " << v[i] << "\n";
    // cout << len << "\n";
    len -= 2;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}