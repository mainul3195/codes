#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        while (i < n && s[i] == c)
            i++;
        i--;
        tmp.push_back(c);
    }
    if (tmp.size() > 1 && tmp[0] != tmp.back())
        cout << "YES\n";
    else
        cout << "NO\n";
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