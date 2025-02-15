#include <bits/stdc++.h>
using namespace std;

long long mod;
int len;
vector<int> v;
void solve()
{
    long long n, k;
    cin >> n >> k;
    mod = pow(10, k) + .5;
    n %= len;
    if (!n)
        n = len;
    cout << v[n] % mod << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    int md = pow(10, 6) + .5;
    int a = 1, b = 2, c = 3;
    len = 3;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    while (1)
    {
        int d = (a + b + c) % md;
        a = b;
        b = c;
        c = d;
        if (a == 1 && b == 2 && c == 3)
            break;
        v.push_back(d);
        len++;
    }
    len -= 3;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}