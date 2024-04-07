#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    int ans = 0, tmp_ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (mp[x] && i - mp[x] <= tmp_ans)
            tmp_ans = i - mp[x];
        else
            tmp_ans++;
        ans = max(ans, tmp_ans);
        mp[x] = i;
    }
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}