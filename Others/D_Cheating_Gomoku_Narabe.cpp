#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    for (auto &s : v)
        cin >> s;
    int ans = 2000000000;
    if (m >= k)
        for (int i = 0; i < n; i++)
        {
            int len = 0, dot = 0;
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == 'x')
                {
                    len = dot = 0;
                    continue;
                }
                if (v[i][j] == '.')
                    dot++;
                len++;
                if (len == k + 1)
                {
                    if (v[i][j - k] == '.')
                        dot--;
                    len--;
                }
                if (len == k)
                    ans = min(ans, dot);
            }
        }
    if (n >= k)
        for (int i = 0; i < m; i++)
        {
            int len = 0, dot = 0;
            for (int j = 0; j < n; j++)
            {
                if (v[j][i] == 'x')
                {
                    len = dot = 0;
                    continue;
                }
                if (v[j][i] == '.')
                    dot++;
                len++;
                if (len == k + 1)
                {
                    if (v[j - k][i] == '.')
                        dot--;
                    len--;
                }
                if (len == k)
                    ans = min(ans, dot);
            }
        }
    if (ans == 2000000000)
        cout << "-1\n";
    else
        cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}