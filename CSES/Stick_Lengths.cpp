#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    long long minant = v[n / 2];
    long long ans = 0;
    for (auto i : v)
        ans += abs(i - minant);
    cout << ans << "\n";
    return 0;
}