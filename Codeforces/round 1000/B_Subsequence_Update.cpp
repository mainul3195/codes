#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    l--, r--;
    vector<long long> a(v.begin(), v.begin() + l), b(v.begin() + l, v.begin() + r + 1), c(v.begin() + r + 1, v.end());
    // cout << " a -> ";
    // for (auto i : a)
    //     cout << i << " ";
    // cout << "\n";
    // cout << " b -> ";
    // for (auto i : b)
    //     cout << i << " ";
    // cout << "\n";
    // cout << " c -> ";
    // for (auto i : c)
    //     cout << i << " ";
    // cout << "\n\n";
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    sort(c.begin(), c.end());
    long long sum = 0;
    for (auto i : b)
        sum += i;
    long long dif = 0;

    for (int i = 0; i < a.size() && i < b.size(); i++)
    {
        if (a[i] < b[i])
            dif += b[i] - a[i];
        else
            break;
    }
    long long dif1 = 0;
    for (int i = 0; i < c.size() && i < b.size(); i++)
    {
        if (c[i] < b[i])
            dif1 += b[i] - c[i];
        else
            break;
    }
    // cout << dif << " " << dif1 << "\n";
    if (dif > dif1)
        cout << sum - dif << "\n";
    else
        cout << sum - dif1 << "\n";
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