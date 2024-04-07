#include <bits/stdc++.h>
using namespace std;
#define N 500005
int n, q, mx_level;
vector<int> adj[N], *tree_nodes[N];
int sz[N], level[N], pal[N], ans[N];
char w[N];
vector<pair<int, int>> query[N];

void find_sz(int u = 1, int cur_l = 1)
{
    sz[u] = 1;
    level[u] = cur_l;
    int mx_depth = 0;
    for (auto v : adj[u])
    {
        find_sz(v, cur_l + 1);
        sz[u] += sz[v];
    }
}
void small_to_large(int u = 1, bool big = 0)
{
    int bigChild = -1, mx = -1;
    for (auto v : adj[u])
        if (sz[v] > mx)
            mx = sz[v], bigChild = v;
    for (auto v : adj[u])
        if (v != bigChild)
            small_to_large(v, 0);
    if (bigChild != -1)
    {
        small_to_large(bigChild, 1);
        tree_nodes[u] = tree_nodes[bigChild];
    }
    else
    {
        tree_nodes[u] = new vector<int>();
        mx_level = level[u];
    }
    tree_nodes[u]->push_back(u);
    if (pal[level[u]] == -1)
        pal[level[u]] = 0;
    pal[level[u]] ^= (1 << (w[u] - 'a'));
    for (auto v : adj[u])
        if (v != bigChild)
            for (auto x : *tree_nodes[v])
            {
                mx_level = max(mx_level, level[x]);
                tree_nodes[u]->push_back(x);
                if (pal[level[x]] == -1)
                    pal[level[x]] = 0;
                pal[level[x]] ^= (1 << (w[x] - 'a'));
            }
    for (auto [h, ind] : query[u])
        ans[ind] = (h<level[u]) || (h>mx_level) || (__builtin_popcount(pal[h]) <= 1);
    if (!big)
    {
        for (auto v : *tree_nodes[u])
            pal[level[v]] = -1;
        mx_level = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(pal, -1, sizeof(pal));
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 0; i < q; i++)
    {
        int u, h;
        cin >> u >> h;
        query[u].push_back({h, i});
    }
    find_sz();
    small_to_large();
    for (int i = 0; i < q; i++)
        cout << (ans[i] ? "Yes" : "No") << "\n";
    return 0;
}