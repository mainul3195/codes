#include <bits/stdc++.h>
using namespace std;
int n, mx;
vector<long long> bit;
long long qr(long long x)
{
    long long ans = 0;
    for (; x > 0; x -= (x & (-x)))
        ans += bit[x];
    return ans;
}
void upd(long long x, long long val)
{
    for (; x <= mx; x += (x & (-x)))
        bit[x] += val;
}
struct nd
{
    int l, r, ind;
    bool operator<(const nd &a) const
    {
        return l < a.l || (l == a.l && r > a.r);
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bit = vector<long long>(500000, 0);
    cin >> n;
    set<int> st;
    vector<nd> v(n);
    int count = 0;
    for (auto &[a, b, in] : v)
    {
        cin >> a >> b;
        in = count++;
        st.insert(a);
        st.insert(b);
    }
    count = 1;
    map<int, int> mp;
    for (auto i : st)
        mp[i] = count++;
    mx = st.size() + 5;
    for (auto &[a, b, in] : v)
    {
        a = mp[a];
        b = mp[b];
    }
    vector<int> ans2(n), ans1(n);
    sort(v.begin(), v.end());
    for (auto [l, r, i] : v)
    {
        ans2[i] = qr(mx) - qr(r - 1);
        upd(r, 1);
    }
    bit = vector<long long>(500000, 0);
    reverse(v.begin(), v.end());
    for (auto [l, r, i] : v)
    {
        ans1[i] = qr(r) - qr(l - 1);
        upd(r, 1);
    }
    for (auto i : ans1)
        cout << i << " ";
    cout << "\n";
    for (auto i : ans2)
        cout << i << " ";
    cout << "\n";
    return 0;
}