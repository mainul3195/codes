#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> bit;
int qr(int ind)
{
    int ans = 0;
    for (; ind; ind -= (ind & (-ind)))
        ans += bit[ind];
    return ans;
}
void upd(int ind, int val)
{
    for (; ind <= n; ind += (ind & (-ind)))
        bit[ind] += val;
    return;
}
void solve()
{
    cin >> n;
    bit = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++)
        upd(i, 1);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int h, t;
        cin >> h >> t;
        v.push_back({h, t});
    }
    sort(v.begin(), v.end());
    vector<int> pos(n, -1);
    for (int i = 0; i < n; i++)
    {
        int l = 1, r = n, mid, ans = -1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            int tot = qr(mid);
            if (tot >= v[i].second + 1)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        if (ans == -1)
        {
            cout << "No ordering possible!\n";
            return;
        }
        // cout << " -> " << ans << "\n";
        upd(ans, -1);
        pos[ans - 1] = v[i].first;
    }
    for (int i = 0; i < n; i++)
        cout << pos[i] << " \n"[i == n - 1];
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}