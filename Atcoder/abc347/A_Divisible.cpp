#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % k == 0)
            v.push_back(x / k);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " \n"[i == v.size() - 1];
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}