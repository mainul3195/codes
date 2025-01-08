#include <bits/stdc++.h>
using namespace std;

vector<long long> bit;
int sz;
long long qr(long long x)
{
    long long ans = 0;
    for (; x > 0; x -= (x & (-x)))
        ans += bit[x];
    return ans;
}
void upd(long long x, long long val)
{
    for (; x <= sz; x += (x & (-x)))
        bit[x] += val;
}
void solve()
{
    int n;
    long long x, y;
    cin >> n >> x >> y;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    set<int> st;
    for (auto i : v)
        st.insert(i);
    long long sum = 0;
    for (auto i : v)
        sum += i;
    for (auto i : v)
    {
        long long low = sum - i - y;
        long long high = sum - i - x;
        if (high < 0)
            continue;
        low = max(low, 0LL);
        st.insert(high);
        st.insert(low);
    }
    sz = 1;
    map<int, int> mp;
    for (auto i : st)
        mp[i] = sz++;
    bit = vector<long long>(sz + 1, 0);
    long long ans = 0;
    for (auto i : v)
    {
        long long low = sum - i - y;
        long long high = sum - i - x;
        if (high < 0)
        {
            upd(mp[i], 1);
            continue;
        }
        low = max(low, 0LL);
        ans += qr(mp[high]) - qr(mp[low] - 1);
        upd(mp[i], 1);
    }
    cout << ans << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}