#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n, m;
vector<string> grid;
long long dp[50][50][50][11];
long long okdone(int l = 0, int r = n-1, int k = 0, int mn = 0)
{
    if(l>r)
        return 1;
    if(mn == 10)
        return 0;
    if(k==m)
        return l==r;
    if((grid[l][k] != '?') && (grid[l][k]-'0'!=mn))
        return 0;
    long long &ret = dp[l][r][k][mn];
    if(~ret)
        return ret;
    ret = 0;
    for(int val = mn; val<=9; val++)
    {
        long long tmp = 1;
        for(int i = l; i<=r; i++)
        {
            if(grid[i][k] == '?' || (grid[i][k]-'0' == val))
            {
                tmp = tmp*okdone(l, i, k+1, 0)%mod;
                tmp = tmp*okdone(i+1, r, k, mn+1)%mod;
            }
            else tmp = 0;
        }
        ret = (ret+tmp)%mod;
    }
    return ret;
}
void solve()
{   
    cin >> n >> m;
    grid = vector<string> (n);
    for(auto &s: grid)
        cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << okdone() << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}