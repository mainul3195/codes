#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    long long mx = 0;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        mx = max(x, mx);
    }
    while (q--)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (c == '+')
        {
            if (mx >= l && mx <= r)
                mx++;
        }
        else
        {
            if (mx >= l && mx <= r)
                mx--;
        }
        cout << mx << " ";
    }
    cout << '\n';
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}