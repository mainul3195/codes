#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int ar[26] = {0};
    for (auto c : s)
        ar[c - 'A']++;
    int cnt = 0;
    for (int i = 0; i < 26; i++)
        if (ar[i] >= i + 1)
            cnt++;
    cout << cnt << "\n";
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