#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    long long c_sum = 0;
    int start = -1;
    for (int i = 0; i < n; i++)
    {
        if (2 * c_sum < v[i])
            start = i;
        c_sum += v[i];
    }
    cout << n - start << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}