#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<long long>> v;
long long find_min(int l1, int r1, int l2, int r2)
{
    long long mn = 2000000000;
    for (int i = l1; i <= r1; i++)
        for (int j = l2; j <= r2; j++)
            mn = min(mn, v[i][j]);
    return mn;
}
void solve()
{
    int n;
    cin >> n;
    v = vector<vector<long long>>(n + 1, vector<long long>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> v[i][j];
    long long ans = v[n / 2][n / 2];

    // dui ta
    long long mn1 = 2000000000, mn2 = 2000000000;
    for (int i = 1; i < n / 2; i++)
        mn1 = min(mn1, v[i][n / 2]);
    for (int i = n / 2 + 1; i <= n; i++)
        mn2 = min(mn2, v[i][n / 2]);
    ans = min(ans, mn1 + mn2);
    mn1 = 2000000000, mn2 = 2000000000;
    for (int i = 1; i < n / 2; i++)
        mn1 = min(mn1, v[n / 2][i]);
    for (int i = n / 2 + 1; i <= n; i++)
        mn2 = min(mn2, v[n / 2][i]);
    ans = min(ans, mn1 + mn2);

    // tin ta
    long long mn = 2000000000;
    for (int i = 1; i < n / 2; i++)
        mn = min(mn, v[i][n / 2]);
    ans = min({ans, mn + find_min(n / 2, n, 1, n / 2 - 1) + find_min(n / 2, n, n / 2 + 1, n)});
    mn = 2000000000;
    for (int i = n / 2 + 1; i < n; i++)
        mn = min(mn, v[i][n / 2]);
    ans = min({ans, mn + find_min(1, n / 2 - 1, 1, n / 2 - 1) + find_min(1, n / 2 - 1, n / 2 + 1, n)});

    mn = 2000000000;
    for (int i = 1; i < n / 2; i++)
        mn = min(mn, v[n/2][i]);
    ans = min({ans, mn + find_min(1, n/2-1, n/2, n) + find_min(n / 2, n, n / 2 + 1, n)});
    mn = 2000000000;
    for (int i = n / 2 + 1; i < n; i++)
        mn = min(mn, v[n/2][i]);
    ans = min({ans, mn + find_min(1, n / 2 - 1, 1, n / 2 - 1) + find_min(1, n / 2 - 1, n / 2 + 1, n)});

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