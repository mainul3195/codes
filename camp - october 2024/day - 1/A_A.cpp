#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int ar[3] = {0};
    for (auto c : s)
        ar[c - 'a']++;
    int lim = (int)s.size() / 3;

    if ((ar[0] == lim || ar[0] == lim + 1) &&
        (ar[1] == lim || ar[1] == lim + 1) &&
        (ar[2] == lim || ar[2] == lim + 1))
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}