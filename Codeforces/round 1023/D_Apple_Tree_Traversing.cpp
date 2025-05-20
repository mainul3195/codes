#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int n;
vector<int> par;
void find_par(int u, int p)
{
    par[u] = p;
    for (auto v : adj[u])
        if (!par[u])
            find_par(v, u);
    return;
}
struct nd_content
{
    int nd, len, l, r;
    bool operator<(const nd_content &a)const
    {
        return (len>a.len) || ((len == a.len) && (l>a.l)) || ((len == a.len) && (l==a.l) && (r>a.r));
    }
};
vector<nd_content> contents;
vector<int> vis;
set<nd_content> content_set;
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.first > p2.first) || ((p1.first == p2.first) && (p1.second > p2.second));
}
pair<int, int> fill_contents(int u = 1)
{
    vis[u] = 1;
    vector<pair<int, int>> vecs;
    for (auto v : adj[u])
        if (!vis[v])
            vecs.push_back(fill_contents(v));
    sort(vecs.begin(), vecs.end(), cmp);
    if(vecs.size()>=2)
    {
        contents[u].len = vecs[0].first+vecs[1].first+1;
        contents[u].l = vecs[0].second;
        contents[u].r = vecs[1].second;
    }
    else if(vecs.size() == 1)
    {
        contents[u].len = vecs[0].first+1;
        contents[u].l = max(u, vecs[0].second);
        contents[u].r = min(u, vecs[0].second);
    }
    else
    {
        contents[u].len = 1;
        contents[u].l = u;
        contents[u].r = u;
    }
    contents[u].nd = u;
    content_set.insert(contents[u]);
    if(vecs.size())
        return {vecs[0].first+1, vecs[0].second};
    return {1, u};
}
void solve()
{
    cin >> n;
    adj = vector<vector<int>>(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par = vector<int>(n + 1, 0);
    find_par(1, -1);
    contents = vector<nd_content>(n + 1);
    vis = vector<int>(n + 1, 0);
    fill_contents();
    for(int i = 1; i<=8; i++)
    {
        auto [nd, len, l, r] = contents[i];
        cout << i << " -> " << nd << " " << len << " " << l << " " << r << "\n";
    }
    vis = vector<int>(n+1, 0);
    while(content_set.size())
    {
        auto [nd, len, l, r] = *(content_set.begin());
        int cur = l;
        while(!vis[cur] && (cur!=nd))
        {
            content_set.erase(content_set.find(contents[cur]));
            vis[cur] = 1;
            cur = par[cur];
        }
        cur = r;
        while(!vis[cur] && (cur!=nd))
        {
            content_set.erase(content_set.find(contents[cur]));
            vis[cur] = 1;
            cur = par[cur];
        }
        vis[nd] = 1;
        content_set.erase(content_set.begin());
        cout << len << " " << l << " " << r << " ";
        
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}