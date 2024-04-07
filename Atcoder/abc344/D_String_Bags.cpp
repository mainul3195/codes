#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000
string t;
int n;
vector<vector<string>> s;
int dp[105][105];
int okdone(int i = 0, int k = 0)
{
    if (k == t.size())
        return 0;
    if (i == n)
        return inf;
    if (~dp[i][k])
        return dp[i][k];
    int ans = okdone(i + 1, k);
    for (int j = 0; j < s[i].size(); j++)
    {
        if ((t.size() - k >= s[i][j].size()) && (t.substr(k, s[i][j].size()) == s[i][j]))
            ans = min(ans, 1 + okdone(i + 1, k + s[i][j].size()));
    }
    // cout << i << " : " << k << " -> " << ans << "\n";
    return dp[i][k] = ans;
}
void solve()
{
    cin >> t;
    cin >> n;
    s = vector<vector<string>>(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        while (m--)
        {
            string tmp;
            cin >> tmp;
            s[i].push_back(tmp);
        }
    }
    memset(dp, -1, sizeof(dp));
    int a = okdone();
    if (a == inf)
        a = -1;
    cout << a << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}