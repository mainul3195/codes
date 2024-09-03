#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> lft, rght;
vector<int> ar1, ar2;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if (n % 2 == 0)
    {
        ar1 = ar2 = vector<int>(26, 0);
        for (int i = 0; i < n; i += 2)
            ar1[s[i] - 'a']++;
        for (int i = 1; i < n; i += 2)
            ar2[s[i] - 'a']++;
        int mx1 = 0, mx2 = 0;
        for (int i = 0; i < 26; i++)
            mx1 = max(mx1, ar1[i]);
        for (int i = 0; i < 26; i++)
            mx2 = max(mx2, ar2[i]);
        // cout << mx1 << " " << mx2 << "\n";
        cout << n - mx1 - mx2 << "\n";
        return;
    }
    if (n == 1)
    {
        cout << 1 << "\n";
        return;
    }
    lft = rght = vector<vector<int>>(26, vector<int>(2, 0));
    for (int i = 0; i < n - 1; i++)
        lft[s[i] - 'a'][i % 2]++;

    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < 26; i++)
        mx1 = max(mx1, lft[i][0]), mx2 = max(mx2, lft[i][1]);
    int ans = n - mx1 - mx2;

    rght[s[n - 1] - 'a'][0]++;
    for (int i = n - 2; i > 0; i--)
    {
        lft[s[i] - 'a'][i % 2]--;
        mx1 = mx2 = 0;
        for (int j = 0; j < 26; j++)
        {
            mx1 = max(mx1, lft[j][0] + rght[j][1]);
            mx2 = max(mx2, lft[j][1] + rght[j][0]);
        }
        rght[s[i] - 'a'][i % 2]++;
        ans = min(ans, n - mx1 - mx2);
    }
    // rght[s[0] - 'a'][0]++;
    mx1 = 0, mx2 = 0;
    for (int i = 0; i < 26; i++)
        mx1 = max(mx1, rght[i][0]), mx2 = max(mx2, rght[i][1]);
    ans = min(ans, n - mx1 - mx2);
    cout << ans << "\n";
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