#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int mx = -1;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        int count = 0;
        while (i < s.size() && s[i] == c)
        {
            count++;
            i++;
        }
        i--;
        mx = max(mx, count);
    }
    cout << mx << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}