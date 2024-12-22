#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<long long> cum;
vector<int> x;
int n, q;
long long bit[200005];
long long qr(long long x)
{
    long long ans = 0;
    for (; x > 0; x -= (x & (-x)))
        ans += bit[x];
    return ans;
}
void upd(long long x, long long val)
{
    for (; x <= n; x += (x & (-x)))
        bit[x] += val;
}
struct qrs
{
    int l, r, ind;
    long long ans;
    bool operator<(const qrs &a) const
    {
        return l > a.l || (l == a.l && r > a.r);
    }
};
struct Pair
{
    int mx_val, ind;
    bool operator<(const Pair &a) const
    {
        return ind < a.ind;
    }
};
bool cmp(qrs &a, qrs &b)
{
    return a.ind < b.ind;
}
void solve()
{
    cin >> n >> q;
    cum = vector<long long>(n + 1, 0);
    x = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        cum[i] = cum[i - 1] + x[i];
    }
    vector<qrs> query(q);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        query[i].l = l;
        query[i].r = r;
        query[i].ind = i;
    }
    sort(query.begin(), query.end());

    int last = n + 1;
    vector<Pair> pr, stk;
    for (auto &[l, r, ind, ans] : query)
    {
        if (last > l)
        {
            int prev = 0;
            for (int i = l; i < last; i++)
            {
                if (x[i] > prev)
                {
                    prev = x[i];
                    if (pr.size())
                    {
                        auto &[v, ind] = pr.back();
                        upd(ind, (i - ind - 1) * v - cum[i - 1] + cum[ind] - qr(ind) + qr(ind - 1));
                    }
                    pr.push_back({x[i], i});
                }
            }
            last = l;
            while (stk.size() && stk.back().mx_val <= pr.back().mx_val)
            {
                upd(stk.back().ind, -qr(stk.back().ind) + qr(stk.back().ind - 1));
                stk.pop_back();
            }
            if (stk.size())
                upd(pr.back().ind, qr(pr.back().ind) - qr(pr.back().ind - 1) + (stk.back().ind - pr.back().ind - 1) * pr.back().mx_val - cum[stk.back().ind - 1] + cum[pr.back().ind]);
            while (pr.size())
            {
                stk.push_back(pr.back());
                pr.pop_back();
            }
        }
        auto it = upper_bound(stk.rbegin(), stk.rend(), (Pair){-1, r});
        long long temp = 0;
        it--;
        temp = (r - (*it).ind) * (*it).mx_val - cum[r] + cum[(*it).ind];
        if (it - stk.rbegin() > 0)
        {
            it--;
            temp += qr((*it).ind);
        }
        ans = temp;
    }
    sort(query.begin(), query.end(), cmp);
    for (auto [a, b, ind, ans] : query)
        cout << ans << "\n";

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}