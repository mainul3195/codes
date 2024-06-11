#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    string s;
    cin >> n >> m >> s;
    int ar[26] = {0};
    for (auto c : s)
        ar[c - 'A']++;
    int tot = 0;
    for (int i = 0; i <= 6; i++)
        tot += max(0, m - ar[i]);
    cout << tot << "\n";
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