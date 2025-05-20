#include<bits/stdc++.h>
using namespace std;
int n, m;
// bitset<6> bt;
void solve()
{
    cin >> n >> m;
    vector<vector<int>> animals(n+1);
    vector<long long> costs(n+1);
    for(int i = 1; i<=n; i++)
        cin >> costs[i];
    for(int i = 1; i<=m; i++)
    {
        int k;
        cin >> k;
        while(k--)
        {
            int x;
            cin >> x;
            animals[x].push_back(i);
        }
    }
    int zoo[2*n];
    for(int i = 0; i<n; i++)
        zoo[i] = zoo[i+n] = i+1;
    int lim = (1<<(2*n));
    long long ans = 1000000000000000000LL;
    for(int mask = 0; mask<lim; mask++)
    {
        long long tot = 0;
        int mul = 1;
        int ind = 0;
        int vis[m+1] = {0};
        while(mul<lim)
        {
            if(mul&mask)
            {
                int z = zoo[ind];
                tot += costs[z];
                for(auto x: animals[z])
                    vis[x]++;
            }
            mul <<= 1;
            ind++;
        }
        bool ok = 1;
        for(int i = 1; i<=m; i++)
            if(vis[i]<2)
            {
                ok  = 0;
                break;
            }
        if(ok)
            ans = min(ans, tot);
        // bt = mask;
        // cout << bt << "\n";
        // for(int i = 1; i<=m; i++)
        //     cout << vis[i] << " ";
        // cout << "\n";
    }
    cout << ans << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}