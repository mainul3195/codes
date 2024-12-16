#include <bits/stdc++.h>
using namespace std;
int n;
long long bit[100005];
long long qr(long long x)
{
    long long ans = 0;
    for (; x > 0; x -= (x & (-x)))
        ans += bit[x];
    return ans;
}
void upd(long long x, long long val)
{
    for (; x <= n; x += (x & (-x)))
        bit[x] += val;
}
void solve()
{
    cin >> n;
    memset(bit, 0, sizeof(long long) * (n + 2));
    long long ans = 0;
    long long last2 = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (!x || x % 4 == 0)
        {
            ans += i;
            upd(i, 2);
            last2 = i;
        }
        else if (x % 2 == 0)
        {
            upd(i, 1);
            ans += i - (i - last2);
            last2 = i;
        }
        else
        {
            int tot = qr(i);
            int l = 0, r = i, s = -1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                int twos = qr(mid);
                if (twos >= tot - 1)
                {
                    s = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            ans += i - (last2 - s);
        }
    }
    cout << ans << "\n";
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