#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y;
    string s;
    cin >> x >> y >> s;
    int lng = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1')
        {
            int cnt = 0;
            while (i < s.size() && s[i] == '1')
            {
                cnt++;
                i++;
            }
            ans += x * cnt;
            lng = max(lng, cnt);
        }
    cout << ans + lng * y << "\n";
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