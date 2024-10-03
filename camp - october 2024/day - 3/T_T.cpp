#include <bits/stdc++.h>
using namespace std;
int n;
#define mx 100005
int a[mx], lg[mx];
int spt[mx][25];
int lim;
vector<int> sg_tree;
int qr(int l, int r)
{
    int len = r - l + 1;
    int k = lg[len];
    return gcd(spt[l][k], spt[r - (1 << (k)) + 1][k]);
}
int query(int ind, int node = 1, int start = 1, int end = n)
{
    
}
void update(int l, int r, int val, int node = 1, int start = 1, int end = n)
{
    if(start>r || end<l)
        return;
    if(start>=l && end<=r)
    {
        sg_tree[node] = max(sg_tree[node], val);
        return;
    }
    int mid = (start+end)/2;
    update(l, r, val, 2*node, start, mid);
    update(l, r, val, 2*node+1, mid+1, end);
}
void solve()
{
    cin >> n;
    sg_tree = vector<int> (4*n, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    lim = log2(n + .5) + 2;
    for (int i = 1; i <= n; i++)
        spt[i][0] = a[i];
    for (int k = 1; k < lim; k++)
        for (int i = 1; i <= n; i++)
            if (i + (1 << k) - 1 <= n)
                spt[i][k] = gcd(spt[i][k - 1], spt[i + (1 << (k - 1))][k - 1]);
    vector<vector<int>> ins(n + 2), dlt(n + 2);
    for (int i = 1; i <= n; i++)
    {
        int cur_g = 0;
        int r = i - 1;
        while (r + 1 <= n)
        {
            r++;
            int strt = r;
            cur_g = gcd(cur_g, a[r]);
            if (cur_g == 1)
            {
                ins[strt - i + 1].push_back(1);
                dlt[n - i + 1].push_back(1);
                break;
            }
            int lft = strt, rght = n, mid, nd;
            while (lft <= rght)
            {
                mid = (lft + rght) / 2;
                if (qr(i, mid) == cur_g)
                    lft = mid + 1, nd = mid;
                else
                    rght = mid - 1;
            }
            ins[strt - i + 1].push_back(cur_g);
            dlt[nd - i + 1].push_back(cur_g);
            r = nd;
        }
    }

    multiset<int> st;
    for (int i = 1; i <= n; i++)
    {
        for (auto x : ins[i])
            st.insert(x);
        auto it = st.end();
        it--;
        cout << *it << " ";
        for (auto x : dlt[i])
        {
            auto it = st.find(x);
            if (it != st.end())
                st.erase(it);
        }
    }
    cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lg[0] = lg[1] = 0;
    for (int i = 2; i < 100005; i++)
        lg[i] = lg[i / 2] + 1;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}