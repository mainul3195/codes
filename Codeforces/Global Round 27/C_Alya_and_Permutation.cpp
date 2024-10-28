#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int val;
    vector<int> v;
};
nd build(int n)
{
    if (n == 5)
        return {
            5,
            {2, 1, 3, 4, 5}};
    if (n == 6)
        return {
            7,
            {1, 2, 4, 6, 5, 3}};
    if (n == 7)
        return {
            7,
            {2, 4, 5, 1, 3, 6, 7}};
    if (n % 2)
    {
        auto [val, v] = build(n - 1);
        v.push_back(n);
        return {n, v};
    }
    vector<int> v;
    int lim = 1 << ((int)log2(n + .5));
    v.push_back(lim);
    v.push_back(lim - 1);
    v.push_back(lim - 2);
    v.push_back(3);
    v.push_back(1);
    for (int i = 1; i <= n; i++)
        if ((i != lim) && (i != lim - 1) && (i != lim - 2) && (i != 3) && (i != 1))
            v.push_back(i);
    reverse(v.begin(), v.end());
    return {(1 << ((int)log2(n + .5) + 1)) - 1, v};
}
void solve()
{
    int n;
    cin >> n;
    auto [val, v] = build(n);
    cout << val << "\n";
    for (auto i : v)
        cout << i << " ";
    cout << "\n";
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