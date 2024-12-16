#include<bits/stdc++.h>
using namespace std;

#define max_lim 1000006
#define Mod 1000000007
vector<long long>f(max_lim+1);
void precalc()
{
    f[0]=1;
    for(long long i=1; i<=max_lim; i++)
        f[i]=f[i-1]*i%Mod;
}
long long factorial(long long n)
{
    return f[n];
}
long long bigMod(long long b, long long p)
{
    if(!p) return 1;
    if(p&1) return (b*bigMod(b, p-1))%Mod;
    long long T = bigMod(b, p/2);
    return (T*T)%Mod;
}
long long modInverse(long long n)
{
    return bigMod(n, Mod-2);
}
vector<vector<int>> adj;
int n, m;
vector<int> indegree, vis;
int dfs(int u)
{
    vis[u] = 1;
    int cnt = 1;
    for(auto v: adj[u])
        if(!vis[v])
            cnt += dfs(v);
    return cnt;
}
void solve()
{
    cin >> n >> m;
    adj = vector<vector<int>> (n+1);
    indegree = vis = vector<int> (n+1, 0);
    for(int i = 0; i<m ; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v] = 1;
    }
    long long tot = 0;
    vector<int>v;
    for(int i = 1; i<=n; i++)
        if(!indegree[i])
        {
            int tmp = dfs(i);
            tot += tmp;
            v.push_back(tmp);
        }
    long long ans = factorial(tot);
    for(auto i: v)
        ans = ans*modInverse(factorial(i))%Mod;
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    precalc();
    solve(); 
    return 0;
}