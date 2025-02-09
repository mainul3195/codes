#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    vector<int> v;
    v.push_back(0);
    v.push_back(360);
    int cur = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cur += x;
        cur %= 360;
        v.push_back(cur);
    }
    // for (auto i : v)
    //     cout << i << " ";
    // cout << "\n";
    sort(v.begin(), v.end());
    int mx = 0;
    for (int i = 1; i < v.size(); i++)
        mx = max(mx, v[i] - v[i - 1]);
    cout << mx << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}