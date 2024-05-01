#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i * (2 * i - 1);
    cout << sum << " " << (2 * n - 1) << "\n";
    cout << 1 << " " << 1 << " ";
    for (int i = n; i >= 1; i--)
        cout << i << " ";
    cout << "\n";
    for (int i = 2; i <= n; i++)
    {
        cout << 1 << " " << i << " ";
        for (int j = n; j >= 1; j--)
            cout << j << " ";
        cout << "\n";
        cout << 2 << " " << i << " ";
        for (int j = n; j >= 1; j--)
            cout << j << " ";
        cout << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}