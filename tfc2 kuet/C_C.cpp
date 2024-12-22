#include <bits/stdc++.h>
using namespace std;
int n;
#define max_val 20000000000000LL
vector<vector<long long>> v;
long long find_min(int l1, int r1, int l2, int r2)
{
    long long mn = max_val;
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
    int mid = n / 2 + 1;
    long long ans = v[mid][mid];
    // dui ta
    long long mn1 = max_val, mn2 = max_val;
    for (int i = 1; i < mid; i++)
        mn1 = min(mn1, v[i][mid]);
    for (int i = mid + 1; i <= n; i++)
        mn2 = min(mn2, v[i][mid]);
    ans = min(ans, mn1 + mn2);
    mn1 = max_val, mn2 = max_val;
    for (int i = 1; i < mid; i++)
        mn1 = min(mn1, v[mid][i]);
    for (int i = mid + 1; i <= n; i++)
        mn2 = min(mn2, v[mid][i]);
    ans = min(ans, mn1 + mn2);

    // tin ta
    long long mn = max_val;
    for (int i = 1; i < mid; i++)
        mn = min(mn, v[i][mid]);
    ans = min({ans, mn + find_min(mid, n, 1, mid - 1) + find_min(mid, n, mid + 1, n)});
    mn = max_val;
    for (int i = mid + 1; i <= n; i++)
        mn = min(mn, v[i][mid]);
    ans = min({ans, mn + find_min(1, mid, 1, mid - 1) + find_min(1, mid, mid + 1, n)});

    mn = max_val;
    for (int i = 1; i < mid; i++)
        mn = min(mn, v[mid][i]);
    ans = min({ans, mn + find_min(1, mid - 1, mid, n) + find_min(mid + 1, n, mid, n)});
    mn = max_val;
    for (int i = mid + 1; i <= n; i++)
        mn = min(mn, v[mid][i]);
    ans = min({ans, mn + find_min(1, mid - 1, 1, mid) + find_min(mid + 1, n, 1, mid)});

    ans = min({ans, find_min(1, mid - 1, 1, mid - 1) + find_min(mid + 1, n, 1, mid - 1) + find_min(1, mid - 1, mid + 1, n) + find_min(mid + 1, n, mid + 1, n)});
    cout << ans << "\n";
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