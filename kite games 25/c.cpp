#include <bits/stdc++.h>
using namespace std;
int a[100005], st[100005][21], lg[100005];
int find(int l, int r)
{
    int j = lg[r - l + 1];
    return gcd(st[l][j], st[r - (1 << j) + 1][j]);
}
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        st[i][0] = a[i];
    }
    int lim = log2(n) + 2;
    for (int j = 1; j < lim; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        long long sum = 0;
        int i = l;
        while (i <= r)
        {
            long long cur = find(l, i);
            int left = i, right = r, mid, ans = i;
            while (left <= right)
            {
                mid = (left + right) / 2;
                if (find(l, mid) == cur)
                {
                    ans = mid;
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
            sum += cur * (ans - i + 1);
            i = ans + 1;
        }
        cout << sum << "\n";
    }

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lg[0] = lg[1] = 0;
    for (int i = 2; i < 100005; i++)
        lg[i] = lg[i / 2] + 1;
    solve();
    return 0;
}