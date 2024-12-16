#include<bits/stdc++.h>
using namespace std;
int dp[1000006];
int okdone(int u)
{
    // cout << u << endl;
    if(!u)
        return 0;
    if(~dp[u])
        return dp[u];
    int mn = 1000000000;
    if(u%2 == 0)
        mn = min(mn, okdone(u/2));
    if(u%3 == 0)
        mn = min(mn, okdone(u/3));
    mn = min(mn, okdone(u-1));
    return dp[u] = mn+1;
}
void solve()
{
    int n;
    cin >> n;
    cout << okdone(n) << "\n";
    // cout << dp[n] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    memset(dp, -1, sizeof(dp));
    cin >> t;
    while(t--)
        solve();
    return 0;
}