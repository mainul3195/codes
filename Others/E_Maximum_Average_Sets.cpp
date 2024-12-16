#include <bits/stdc++.h>
using namespace std;
#define int long long
long long nCr(long long n, long long r)
{
    long long C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = min(i, r); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[r];
}
vector<long long> v;
int n, a, b;
long long count_ways(int taken)
{
    int t = v[taken - 1];
    int after = 0;
    for (int i = taken; i < n && v[i] == t; i++)
        after++;
    int before = 0;
    for (int i = taken - 1; i >= 0 && v[i] == t; i--)
        before++;
    // cout << taken << " -> " << before << " " << after << " " << nCr(before + after, before) << "\n";
    return nCr(before + after, before);
}
void solve()
{
    cin >> n >> a >> b;
    v = vector<long long>(n);
    for (auto &i : v)
        cin >> i;
    sort(v.rbegin(), v.rend());
    int t = v[a - 1];
    long long tot = count_ways(a);
    if (v[0] == v[a-1])
        for (int i = a+1; i <= b && v[i-1] == t; i++)
            tot += count_ways(i);
    double d = 0;
    for (int i = 0; i < a; i++)
        d += v[i];
    cout << fixed << setprecision(8) << d / a << "\n";
    cout << tot << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}