#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
vector<int> bt[2];
int n, lim;
void update(int ind, int t)
{
    for (int i = ind; i <= lim; i += (i & (-i)))
        bt[t][i]++;
    return;
}
long long query(int ind, int t)
{
    long long ans = 0;
    for (int i = ind; i; i -= (i & (-i)))
        ans += bt[t][i];
    return ans;
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
void solve()
{
    cin >> n;
    lim = n << 1;
    v = vector<pair<int, int>>(n);
    bt[0] = bt[1] = vector<int>(lim + 1, 0);
    for (auto &[a, b] : v)
    {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto [a, b] : v)
    {
        if (query(a, 0) != query(b, 0))
        {
            cout << "Yes\n";
            return;
        }
        update(b, 0);
    }
    cout << "No\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}