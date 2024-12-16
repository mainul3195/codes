#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> v;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x - i);
    }
    sort(v.begin(), v.end());
    int mid = v[n / 2];

    long long tot = 0;
    for (auto i : v)
        tot += abs(i - mid);
    cout << tot << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}