    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    int n, q;

    vector<vector<int>> adj;
    vector<long long> val, prefix_xor, sg_tree;
    map<long long, long long> mp;
    vector<vector<int>> spt;
    vector<int> lvl, in, out;
    int lim, cur_time;
    void update(int l, int r, long long val, int node = 1, int start = 1, int end = n)
    {
        if (start > r || end < l)
            return;
        if (start >= l && end <= r)
        {
            sg_tree[node] ^= val;
            return;
        }
        int mid = (start + end) / 2;
        update(l, r, val, 2 * node, start, mid);
        update(l, r, val, 2 * node + 1, mid + 1, end);
        return;
    }
    long long query(int ind, int node = 1, int start = 1, int end = n)
    {
        if (start == end)
            return sg_tree[node];
        int mid = (start + end) / 2;
        return sg_tree[node] ^ (ind <= mid ? query(ind, 2 * node, start, mid) : query(ind, 2 * node + 1, mid + 1, end));
    }
    void dfs(int u = 1, int p = -1, int l = 1, long long xr = 0)
    {
        xr ^= val[u];
        in[u] = ++cur_time;
        lvl[u] = l;
        spt[u][0] = p;
        for (auto v : adj[u])
            if (v != p)
                dfs(v, u, l + 1, xr);
        out[u] = cur_time;
        return;
    }
    pair<int, int> lca(int u, int v)
    {
        int dis = 0;
        if (lvl[u] < lvl[v])
            swap(u, v);
        int dif = lvl[u] - lvl[v];
        dis += dif;
        for (int k = lim - 1; k >= 0 && dif; k--)
        {
            if ((1LL << k) <= dif)
            {
                dif -= (1LL << k);
                u = spt[u][k];
            }
        }
        if (u == v)
            return {u, dis};
        for (int k = lim - 1; k >= 0; k--)
        {
            if (spt[u][k] != spt[v][k])
            {
                dis += (1LL << (k + 1));
                u = spt[u][k];
                v = spt[v][k];
            }
        }
        return {spt[u][0], dis + 2};
    }
    void printtree()
    {
        for (int i = 1; i <= 30; i++)
            cout << i << " -> " << sg_tree[i] << "\n";
        return;
    }
    void solve()
    {
        cin >> n >> q;
        lim = log2(n + .5) + 2;
        lvl = in = out = vector<int>(n + 1, 0);
        spt = vector<vector<int>>(n + 1, vector<int>(lim, -1));
        adj = vector<vector<int>>(n + 1);
        val = prefix_xor = vector<long long>(n + 1, 0);
        sg_tree = vector<long long>(4 * n, 0);
        mp.clear();
        srand(time(0));
        for (int i = 1; i <= n; i++)
        {
            mp[i] = ((long long)rand()) * rand();
            prefix_xor[i] = prefix_xor[i - 1] ^ mp[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> val[i];
            if (mp.find(val[i]) == mp.end())
                mp[val[i]] = ((long long)rand()) * rand();
            val[i] = mp[val[i]];
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cur_time = 0;
        dfs();
        for (int i = 1; i <= n; i++)
            update(in[i], out[i], val[i]);
        // printtree();
        for (int k = 1; k < lim; k++)
            for (int i = 1; i <= n; i++)
                if (spt[i][k - 1] != -1)
                    spt[i][k] = spt[spt[i][k - 1]][k - 1];
        while (q--)
        {
            int t, a, b;
            cin >> t >> a >> b;
            if (t == 1)
            {
                auto [l, d] = lca(a, b);
                d++;
                if ((query(in[a]) ^ query(in[b]) ^ val[l]) == prefix_xor[d])
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
            else
            {
                if (mp.find(b) == mp.end())
                    mp[b] = (long long)rand() * rand();
                update(in[a], out[a], val[a] ^ mp[b]);
                val[a] = mp[b];
            }
        }
        return;
    }
    int32_t main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t;
        cin >> t;
        while (t--)
            solve();
        return 0;
    }