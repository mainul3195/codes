#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    bool ok = 0;
    for (int i = 0; i + k <= n; i++)
    {
        long long sum = 0;
        for (int j = i; j < i + k - 1; j++)
            sum += v[j];
        if (sum > v[i + k - 1])
        {
            ok = 1;
            break;
        }
    }
    if (ok)
        cout << "Yes\n";
    else
        cout << "No\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}