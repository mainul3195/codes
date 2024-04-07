#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n, sparse_table[N][20], level[N], ans[N], sz[N], cnt[N];
vector<int> adj[N], roots, *tree_nodes[N];
vector<pair<int, int>> query[N];
void dfs(int u, int l = 1)
{
    level[u] = l;
    sz[u] = 1;
    for (auto v : adj[u])
    {
        sparse_table[v][0] = u;
        dfs(v, l + 1);
        sz[u] += sz[v];
    }
}

void small_to_large(int u, bool big = 0)
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
        tree_nodes[u] = new vector<int>();
    tree_nodes[u]->push_back(u);
    cnt[level[u]]++;
    for (auto v : adj[u])
        if (v != bigChild)
            for (auto x : *tree_nodes[v])
            {
                tree_nodes[u]->push_back(x);
                cnt[level[x]]++;
            }
    for (auto [h, ind] : query[u])
        ans[ind] = max(0, cnt[level[u] + h] - 1);

    if (!big)
        for (auto v : *tree_nodes[u])
            cnt[level[v]]--;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u;
        cin >> u;
        if (u)
            adj[u].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        if (!level[i])
            dfs(i), roots.push_back(i);
    for (int i = 1; i < 18; i++)
        for (int j = 1; j <= n; j++)
            sparse_table[j][i] = sparse_table[sparse_table[j][i - 1]][i - 1];
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int v, h;
        cin >> v >> h;
        int tmp = h, p = v;

        for (int i = 18; i >= 0; i--)
            if (1 << i <= tmp)
            {
                tmp -= 1 << i;
                p = sparse_table[p][i];
            }
        if (p)
            query[p].push_back({h, i});
    }
    for (auto i : roots)
        small_to_large(i);
    for (int i = 0; i < q; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}