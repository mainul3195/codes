#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    if (t == s)
    {
        cout << "1\n";
        return;
    }
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i && s[i] == '0' && s[i - 1] == '1')
            cnt++;
        if (i < s.size() - 1 && s[i] == '0' && s[i + 1] == '1')
            cnt++;
    }
    if (cnt > 1)
        cnt--;
    cout << cnt + 1 << "\n";
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