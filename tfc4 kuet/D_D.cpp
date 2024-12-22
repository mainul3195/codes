#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int s, t, x;
    cin >> s >> t >> x;
    if (t < s)
        t += 24;
    if (x < s)
        x += 24;
    if (x >= s && x < t)
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