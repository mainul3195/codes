#include <bits/stdc++.h>
using namespace std;
long long bit[26][500005];
long long qr(long long x, int ind)
{
    long long ans = 0;
    for (; x > 0; x -= (x & (-x)))
        ans += bit[ind][x];
    return ans;
}
void upd(long long x, long long val, int ind)
{
    for (; x <= 500000; x += (x & (-x)))
        bit[ind][x] += val;
}
void solve()
{
    int n, q;
    string s;
    cin >> n >> s >> q;
    for (int i = 0; i < n; i++)
        upd(i + 1, 1, s[i] - 'a');
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i;
            char c;
            cin >> i >> c;
            if (s[i - 1] == c)
                continue;
            upd(i, -1, s[i - 1] - 'a');
            upd(i, 1, c - 'a');
            s[i - 1] = c;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int cnt = 0;
            for (int ind = 0; ind < 26; ind++)
                if (qr(r, ind) - qr(l - 1, ind) > 0)
                    cnt++;
            cout << cnt << "\n";
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}