#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    long long ans = 0, prev = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] <= t[i])
            prev++;
        if (s[i] < t[i])
            ans += (prev * (n - i));
        if (s[i] != t[i])
            prev = 0;
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