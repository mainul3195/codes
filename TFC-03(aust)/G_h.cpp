#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int i = 0, j = s.size() - 1;
    int cnt = 0;
    while (i < j)
    {
        if (s[i] != s[j])
            cnt++;
        i++, j--;
    }
    cout << cnt << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}