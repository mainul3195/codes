#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int sq = sqrt(n + .5);
    if (sq * sq != n)
    {
        cout << "No\n";
        return;
    }
    for (int i = 0; i < n; i += sq)
    {
        if (i == 0 || i + sq == n)
        {
            for (int j = i; j < i + sq; j++)
                if (s[j] == '0')
                {
                    cout << "No\n";
                    return;
                }
            continue;
        }
        if (s[i] == '0' || s[i + sq - 1] == '0')
        {
            cout << "No\n";
            return;
        }
        for (int j = i + 1; j + 1 < i + sq; j++)
            if (s[j] == '1')
            {
                cout << "No\n";
                return;
            }
    }
    cout << "Yes\n";
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