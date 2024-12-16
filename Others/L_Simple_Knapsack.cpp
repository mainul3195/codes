#include <bits/stdc++.h>
using namespace std;
int n, w, wt[101], val[101];
vector<int> weights;
vector<vector<vector<vector<vector<int>>>>> dp;
map<int, int> mp;
long long okdone(int i = 0, int f = 0, int s = 0, int t = 0, int fo = 0)
{
    if (i == n)
        return 0;
    if (~dp[i][f][s][t][fo])
        return dp[i][f][s][t][fo];
    long long taken = weights[0] * f + weights[1] * s + weights[2] * t + weights[3] * fo;
    long long tot = okdone(i + 1, f, s, t, fo);
    int ind = mp[wt[i]];
    int nf = f, ns = s, nt = t, nfo = fo;
    if (ind == 0)
        nf++;
    else if (ind == 1)
        ns++;
    else if (ind == 2)
        nt++;
    else
        nfo++;
    if (taken + wt[i] <= w)
        tot = max(tot, okdone(i + 1, nf, ns, nt, nfo) + val[i]);
    return dp[i][f][s][t][fo] = tot;
}
void solve()
{
    cin >> n >> w;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
        st.insert(wt[i]);
    }
    int c = 0;
    for (auto i : st)
    {
        mp[i] = c;
        c++;
    }
    int cnt[4] = {0};
    for (int i = 0; i < n; i++)
        cnt[mp[wt[i]]]++;
    weights = vector<int>(4, 0);
    c = 0;
    for (auto i : st)
    {
        weights[c] = i;
        c++;
    }
    dp = vector<vector<vector<vector<vector<int>>>>>(n + 1, vector<vector<vector<vector<int>>>>(cnt[0] + 1, vector<vector<vector<int>>>(cnt[1] + 1, vector<vector<int>>(cnt[2] + 1, vector<int>(cnt[3] + 1, -1)))));
    cout << okdone() << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}