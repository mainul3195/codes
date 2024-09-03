#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    b %= 2;
    if (b == 1)
    {
        if (a >= 2)
            a -= 2, b = 0;
    }
    a %= 2;
    if (a == 0 && b == 0)
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