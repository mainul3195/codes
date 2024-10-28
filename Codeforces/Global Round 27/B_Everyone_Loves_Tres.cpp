#include <bits/stdc++.h>
using namespace std;
string s = "6636";

void solve()
{
    int n;
    cin >> n;
    if (n == 1 || n == 3)
        cout << "-1\n";
    else
    {
        string tmp = s.substr(0, n);
        if (n % 2 == 0 && n > 3)
            tmp[3] = '3';
        reverse(tmp.begin(), tmp.end());
        cout << tmp << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < 1000; i++)
        s += '3';
    while (t--)
        solve();
    return 0;
}