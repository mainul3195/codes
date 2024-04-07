#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    string t;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '.')
            break;
        t.push_back(s[i]);
    }
    reverse(t.begin(), t.end());
    cout << t << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}