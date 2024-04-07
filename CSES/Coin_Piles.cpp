#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long a, b;
    cin >> a >> b;
    if ((a + b) % 3 == 0 && min(a, b) >= (a + b) / 3)
        cout << "YES\n";
    else
        cout << "NO\n";
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