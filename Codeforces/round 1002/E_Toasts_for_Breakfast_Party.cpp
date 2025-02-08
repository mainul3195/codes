#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<long long> v(n), dis;
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++)
    {
        dis.push_back(v.back());
        v.pop_back();
    }
    reverse(dis.begin(), dis.end());
    // for (auto i : dis)
    //     cout << i << " ";
    // cout << "\n";
    // for (auto i : v)
    //     cout << i << " ";
    // cout << "\n";
    int i = 0;
    while (v.size())
    {
        dis[i] += v.back();
        v.pop_back();
        i++;
    }
    // for (auto i : dis)
    //     cout << i << " ";
    // cout << "\n";
    long long ans = 0;
    for (auto i : dis)
        ans += i * i;
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}