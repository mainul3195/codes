#include <bits/stdc++.h>
using namespace std;
int n, mx;
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
    cin >> n;
    vector<nd> v(n);
    int count = 0;
    for (auto &[a, b, in] : v)
    {
        cin >> a >> b;
        in = count++;
    }
    vector<bool> ans2(n, 0), ans1(n, 0);
    sort(v.begin(), v.end());
    mx = -1;
    for (auto [l, r, i] : v)
    {
        if (r <= mx)
            ans2[i] = 1;
        mx = max(mx, r);
    }
    reverse(v.begin(), v.end());
    int mn = 2000000000;
    for (auto [l, r, i] : v)
    {
        if (mn <= r)
            ans1[i] = 1;
        mn = min(mn, r);
    }
    for (auto i : ans1)
        cout << i << " ";
    cout << "\n";
    for (auto i : ans2)
        cout << i << " ";
    cout << "\n";
    return 0;
}