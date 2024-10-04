#include<bits/stdc++.h>
using namespace std;
#define sz 2000006
int n, m;
long long bit[sz];
long long qr(long long x)
{
    long long ans = 0;
    for(;x>0;x-=(x&(-x)))
        ans+=bit[x];
    return ans;
}
void upd(long long x, long long val)
{
    for(;x<=1000005;x+=(x&(-x)))
    bit[x]+=val;
}
vector<int> adj[50004];
vector<int>val;
int ans = (1LL<<31)-1;
void update(int v)
{
    int l = 1, r = v-1, mid, pos1 = 1;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(qr(v)-qr(mid))
        {
            pos1 = mid+1;
            l = mid+1;
        }
        else r = mid-1;
    }
    l = v+1, r = 1000005;
    int pos2 = 1000006;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(qr(mid)-qr(v-1))
        {
            pos2 = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    if(pos1!=1)
        ans = min(ans, v-pos1);
    if(pos2!=1000006)
        ans = min(ans, pos2-v);
    upd(v, 1);
    return;
}
int opt[1000000];
void dfs(int u= 1)
{
    for(auto v: adj[u])
        if(adj[v].size())
            dfs(v);
    for(auto v: adj[u])
        if(adj[v].size() == 0)
            update(val[v]+1000003);
    opt[u] = ans;
    return;
}
void solve()
{
    cin >> n >> m;
    val = vector<int> (n+1, 0);
    for(int i = 2; i<=n; i++)
    {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for(int i = n-m+1; i<=n; i++)
    {
        int v;
        cin >> v;
        val[i] = v;
    }
    dfs();
    for(int i = 1; i<n-m+1; i++)
        cout << opt[i] << " ";
        cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}