#include<bits/stdc++.h>
using namespace std;
int n, q, lim;
int lg[200005];
vector<int>v, start_time, end_time, ar, ending;
vector<vector<int>>adj, sparse_table;
int discovery_time = 0;
void dfs(int u = 1, int par = -1)
{
    start_time[u] = ar[u] = ++discovery_time;
    for(auto v: adj[u])
        if(v != par)
            dfs(v, u);
    end_time[u] = discovery_time;
    return;
}
void build()
{
    for(int i = 1; i<=n; i++)
        sparse_table[i][0] = ar[i];
    for(int k = 1; k<lim; k++)
        for(int i = 1; i<=n; i++)
            if(i+(1LL<<k)-1<=n)
                sparse_table[i][k] = max(sparse_table[i][k-1], sparse_table[i+(1<<(k-1))][k-1]);
}
int query(int l, int r)
{
    int len = r-l+1;
    return max(sparse_table[l][lg[len]], sparse_table[r-(1<<lg[len])+1][lg[len]]);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    lg[0] = lg[1] = 0;
    for(int i = 2; i<200005; i++)
        lg[i] = lg[i/2]+1;
    cin >>n >> q;
    ending = ar = start_time = end_time = v = vector<int>(n+1);
    lim = log2(n)+5;
    sparse_table = vector<vector<int>>(n+1, vector<int>(lim, 0));
    for(int i = 1; i<=n; i++)
        cin >> v[i];
    adj = vector<vector<int>>(n+1);
    for(int i = 1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    build();
    for(int i = 1; i<=n; i++)
        ending[start_time[i]] = end_time[i];
    while(q--)
    {
        int mx = -1;
        int k;
        cin >> k;
        int f;
        cin >> f;
        k--;
        int rs = start_time[f];
        int re = end_time[f];
        vector<int> banned(k);
        for(auto &i: banned)
            cin >> i;
        bool done = 0;
        for(auto i: banned)
        {
            if(start_time[i]<=rs && end_time[i]>=re)
            {
                cout << "-1\n";
                done = 1;
                break;
            }
        }
        if(done)
            continue;
        vector<int> start_times;
        for(auto i: banned)
            if(start_time[i]>=rs)
                start_times.push_back(start_time[i]);
        sort(start_times.begin(), start_times.end());
        int cur = rs+1;
        while(cur<=re)
        {
            int nxt;
            auto it = lower_bound(start_times.begin(), start_times.end(), cur);
            if(it==start_times.end())
                nxt = re;
            else nxt = min(re,(*it) - 1);
            if(cur<=nxt)
                mx = max(mx, query(cur, nxt));
            if(it == start_times.end())
                cur = re+1;
            else cur = ending[*it]+1;
        }
        cout << mx << "\n";
    }

    return 0;
}