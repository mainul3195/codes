#include <bits/stdc++.h>
using namespace std;
#define N 100005
long long color[N], ans[N], mx[N], sz[N], cnt[N];
map<int, int> mp[N];
vector<int> adj[N];
vector<int> *subtree_nodes[N];
int n;

void find_sz(int u = 1, int p = -1)
{
    sz[u] = 1;
    for (auto v : adj[u])
        if (v != p)
        {
            find_sz(v, u);
            sz[u] += sz[v];
        }
}

void small_to_large(int u = 1, int p = -1, bool big = 0)
{
    int bigChild = -1, tmax = -1;
    for (auto v : adj[u])
        if (v != p && sz[v] > tmax)
        {
            tmax = sz[v];
            bigChild = v;
        }
    // cout << u << " -> bigChild: " << bigChild << "\n";

    for (auto v : adj[u])
        if (v != p && v != bigChild)
            small_to_large(v, u, 0);

    if (bigChild != -1)
    {
        small_to_large(bigChild, u, 1);
        subtree_nodes[u] = subtree_nodes[bigChild];
        ans[u] = ans[bigChild];
        mx[u] = mx[bigChild];
    }
    else
        subtree_nodes[u] = new vector<int>();
    subtree_nodes[u]->push_back(u);
    cnt[color[u]]++;
    if (cnt[color[u]] > mx[u])
    {
        mx[u] = cnt[color[u]];
        ans[u] = color[u];
    }
    else if (cnt[color[u]] == mx[u])
        ans[u] += color[u];
    for (auto v : adj[u])
        if (v != p && v != bigChild)
            for (auto x : *subtree_nodes[v])
            {
                cnt[color[x]]++;
                subtree_nodes[u]->push_back(x);
                if (cnt[color[x]] > mx[u])
                {
                    mx[u] = cnt[color[x]];
                    ans[u] = color[x];
                }
                else if (cnt[color[x]] == mx[u])
                    ans[u] += color[x];
            }
    if (!big)
        for (auto v : *subtree_nodes[u])
            cnt[color[v]]--;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
        mp[i][color[i]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_sz();
    // for (int i = 1; i <= n; i++)
    //     cout << sz[i] << " ";
    // cout << "\n";
    small_to_large();
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}