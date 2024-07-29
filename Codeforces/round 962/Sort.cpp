#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> cnta(27, vector<int>(n + 2, 0)), cntb(27, vector<int>(n + 2, 0));
    for (int i = 0; i < n; i++)
    {
        cnta[a[i] - 'a'][i + 1]++;
        cntb[b[i] - 'a'][i + 1]++;
    }
    for (int j = 0; j < 26; j++)
        for (int i = 1; i <= n; i++)
        {
            cnta[j][i] += cnta[j][i - 1];
            cntb[j][i] += cntb[j][i - 1];
        }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = 0; i < 26; i++)
            ans += max(0, cntb[i][r] - cntb[i][l - 1] - cnta[i][r] + cnta[i][l - 1]);
        cout << ans << "\n";
    }
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