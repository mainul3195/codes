#include <bits/stdc++.h>
using namespace std;
#define inf 100000
vector<vector<vector<int>>> dp;
int n;
string str[2];
long long okdone(int i = 0, int f = 0, int s = 0)
{
    if (i == n)
        return 1;
    if (str[0][i] == '#')
        f = 1;
    if (str[1][i] == '#')
        s = 1;
    if (~dp[i][f][s])
        return dp[i][f][s];
    long long tot = 0;
    if (f ^ s)
    {
        if (f == 0)
        {
            if (i < n - 1 && str[0][i + 1] == '.')
                tot += okdone(i + 1, 1, 0);
        }
        else
        {
            if (i < n - 1 && str[1][i + 1] == '.')
                tot += okdone(i + 1, 0, 1);
        }
    }
    else
    {
        tot += okdone(i + 1, 0, 0);
        if (f == 0)
        {
            if ((i < n - 1) && (str[0][i + 1] == '.') && (str[1][i + 1] == '.'))
                tot += okdone(i + 2, 0, 0);
        }
    }
    if (tot > inf)
        tot = inf;
    return dp[i][f][s] = tot;
}
void solve()
{
    cin >> n >> str[0] >> str[1];
    dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(2, -1)));
    long long x = okdone();
    // cout << str[0] << "\n"
    //      << str[1] << "\n";
    // cout << x << "\n";
    if (x == 0)
        cout << "None\n";
    else if (x == 1)
        cout << "Unique\n";
    else
        cout << "Multiple\n";

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