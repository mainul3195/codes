#include <bits/stdc++.h>
using namespace std;
vector<long long> v, cnt;
void solve()
{
    int n, k;
    cin >> n >> k;
    v = vector<long long>(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i < n; i++)
        v.push_back(v[i]);
    for (int i = 2; i < v.size(); i++)
        (v[i] += v[i - 1]) %= k;
    for (auto i : v)
        cout << i << " ";
    cout << "\n";
    long long ans = 0;
    cnt = vector<long long>(k + 1, 0);
    for (int i = 0; i < n; i++)
        cnt[v[i]]++;
    for (auto i : cnt)
        cout << i << " ";
    cout << "\n";
    for (int i = n; i < v.size(); i++)
    {
        ans += cnt[v[i]];
        cnt[v[i]]++;
        cnt[v[i - n]]--;
        cout << i << "->";
        for (auto j : cnt)
            cout << j << " ";
        cout << "\n";
    }
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