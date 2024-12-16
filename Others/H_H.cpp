#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    long long sum = 0;
    for (auto i : v)
        sum += i;
    long long cur = 0;
    for (int i = 1; i <= n; i++)
        cur += (i * v[i - 1]);
    long long mx = cur;
    for (int i = 0; i < n; i++)
    {
        cur = cur - sum + v[i] * n;
        mx = max(mx, cur);
    }
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