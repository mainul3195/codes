#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int l, r, ind, ans;
    bool operator<(const nd &a) const
    {
        return l < a.l || (l == a.l && r < a.r);
    }
};
vector<int> a;
vector<nd> query;
vector<int> bit;
map<int, int> mp;
int n, q;
void update(int ind, int val)
{
    for (; ind <= n; ind += (ind & (-ind)))
        bit[ind] += val;
    return;
}
int sum(int ind)
{
    int ans = 0;
    for (; ind > 0; ind -= (ind & (-ind)))
        ans += bit[ind];
    return ans;
}
bool cmp(nd &a, nd &b)
{
    return a.ind < b.ind;
}
void solve()
{
    cin >> n >> q;
    a = vector<int>(n + 1);
    bit = vector<int>(n + 2, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    query = vector<nd>(q);
    int ind = 0;
    for (auto &[l, r, _, __] : query)
    {
        _ = ind++;
        cin >> l >> r;
    }
    sort(query.rbegin(), query.rend());
    int ptr = n + 1;
    for (auto &[l, r, ind, ans] : query)
    {
        while (ptr > l)
        {
            ptr--;
            if (mp.count(a[ptr]))
                update(mp[a[ptr]], -1);
            mp[a[ptr]] = ptr;
            update(ptr, 1);
        }
        ans = sum(r) - sum(l - 1);
    }
    sort(query.begin(), query.end(), cmp);
    for (auto [a, b, c, d] : query)
        cout << d << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}