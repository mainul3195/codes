#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<int> nw;
    if (n == k)
    {
        for (int i = 1; i < n; i += 2)
            nw.push_back(v[i]);
        nw.push_back(0);
        int cur = 1;
        for (auto i : nw)
        {
            if (i != cur)
                break;
            cur++;
        }
        cout << cur << "\n";
        return;
    }
    int nto = n;
    for (int i = 1; i < n; i++)
    {
        if (v[i] != 1)
        {
            nto = i;
            break;
        }
    }
    if (n - nto >= k - 1)
    {
        cout << "1\n";
        return;
    }
    cout << "2\n";
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