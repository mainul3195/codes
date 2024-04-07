#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<vector<int>> sp_table, tree;
vector<int> level;
void calc_level(int u = 1, int cur = 0)
{
    level[u] = cur;
    for (auto v : tree[u])
        calc_level(v, cur + 1);
}
int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    // cout << n << " " << q << "\n";
    sp_table = vector<vector<int>>(n + 1, vector<int>(log2(n) + 2, -1));
    tree = vector<vector<int>>(n + 1);
    level = vector<int>(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        int j;
        cin >> j;
        sp_table[i][0] = j;
        tree[j].push_back(i);
    }
    calc_level();
    int lim = log2(n) + 1;
    for (int i = 1; i <= lim; i++)
        for (int j = 2; j <= n; j++)
            if (sp_table[j][i - 1] != -1)
                sp_table[j][i] = sp_table[sp_table[j][i - 1]][i - 1];
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (level[u] < level[v])
            u ^= v ^= u ^= v;
        int dif = level[u]-level[v];
        for(int i = lim; i>=0; i--)
            if(1LL<<i <= dif)
            {
                u = sp_table[u][i];
                dif -= 1LL<<i;
            }
        if(u==v)
        {
            cout << u << "\n";
            continue;
        }
        for(int i = lim; i>=0; i--)
            if(sp_table[u][i] != sp_table[v][i])
                u = sp_table[u][i], v = sp_table[v][i];
        cout << sp_table[u][0] << "\n";
    }
    return 0;
}