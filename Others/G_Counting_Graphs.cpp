#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int no_of_child[200005], par[200005];    
long long bigMod(long long b, long long p)
{
    if(!p)
        return 1;
    long long tmp = bigMod(b, p/2);
    tmp = tmp*tmp%mod;
    if(p&1)
        tmp= tmp*b%mod;
    return tmp;
}
struct nd{
    int u, v;
    long long w;
    bool operator<(const nd &a)const
    {
        return w<a.w;
    }
};
int getpar(int u)
{
    if(par[u] == u)
        return u;
    return par[u] = getpar(par[u]);
}
void solve()
{
    int n;
    long long s;
    cin >> n >> s;
    vector<nd> adj(n-1);
    for(auto &[u, v, w]: adj)
        cin >> u >> v >> w;
    sort(adj.begin(), adj.end());
    for(int i = 0; i<=n; i++)
        par[i] = i, no_of_child[i] = 1;
    long long ans = 1;
    for(auto [u, v, w]: adj)
    {
        // cout << u << " " << v << " " << w << " -> ";
        int pu = getpar(u);
        int pv = getpar(v);
        if(pu!=pv)
        {
            // cout << "base = " << max(0ll, s-w+1) << " power = " << (1LL*no_of_child[pu]*no_of_child[pv] - 1)%(mod-1) << " ";
            ans = (ans * bigMod(max(0ll, s-w+1), (1LL*no_of_child[pu]*no_of_child[pv] - 1)%(mod-1)))%mod;
            par[pu] = pv;
            no_of_child[pv]+=no_of_child[pu];
            no_of_child[pu] = 0;
        }
        // cout << ans << "\n";
    }
    cout << ans << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}