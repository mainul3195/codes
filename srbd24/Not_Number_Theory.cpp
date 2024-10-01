#include <bits/stdc++.h>
using namespace std;
string s;
int mx = 0, ones = -1;
void update(int num)
{
    int x = __builtin_popcount(num);
    if (x > ones)
    {
        ones = x;
        mx = num;
    }
    else if (x == ones)
    {
        mx = max(mx, num);
    }
    return;
}
void okdone(int i = 0, int num = 0)
{
    if (i == s.size())
    {
        update(num);
        return;
    }
    if (s[i] != '?')
        okdone(i + 1, num * 10 + (s[i] - '0'));
    else
    {
        for (int j = 0; j <= 9; j++)
            okdone(i + 1, num * 10 + j);
    }
    return;
}
void solve()
{
    cin >> s;
    mx = 0, ones = -1;
    okdone();
    cout << mx << "\n";
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