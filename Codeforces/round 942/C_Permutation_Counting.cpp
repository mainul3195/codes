#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<long long> a;
long long n, k;
bool ok(long long m)
{
    long long need = 0;
    for (auto i : a)
        need += max(0LL, m - i);
    return need <= k;
}
void solve()
{
    cin >> n >> k;
    a = vector<long long>(n);
    for (auto &i : a)
        cin >> i;
    long long l = 0, r = 3000000000000LL, mid, ans;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (ok(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    long long need = 0;
    for (auto i : a)
        need += max(0LL, ans - i);
    long long extra = k - need;
    int exact_count = 0;
    for (auto i : a)
        if (i <= ans)
            exact_count++;
    cout << (ans * n - exact_count + extra + 1) << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}