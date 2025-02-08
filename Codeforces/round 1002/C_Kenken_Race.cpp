#include <bits/stdc++.h>
using namespace std;
bool check(int f, int t, string &s)
{
    vector<int> v(s.size() + 2, 0);
    v[t - 1] = 1;
    for (int i = t - 2; i >= f - 1; i--)
    {
        if (s[i] != '#' && (((s[i + 1] != '#') && v[i + 1]) || (i + 2 < s.size() && (s[i + 2] != '#') && v[i + 2])))
            v[i] = 1;
    }
    return v[f - 1];
}
void solve()
{
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    if (c < b || c < d)
    {
        if (check(a, c, s) && check(b, d, s))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else
    {
        vector<int> v(s.size() + 2, 0);
        v[d - 1] = 1;
        for (int i = d - 2; i >= b - 1; i--)
            if (s[i] != '#' && (((s[i + 1] != '#') && v[i + 1]) || (i + 2 < s.size() && (s[i + 2] != '#') && v[i + 2])))
                v[i] = 1;
        if (v[b - 1])
        {
            int found = -1;
            for (int i = b - 1; i <= d - 1; i++)
            {
                if (
                    v[i] &&
                    (i - 1 >= 0 && s[i - 1] != '#') &&
                    (i + 1 < s.size() && s[i + 1] != '#'))
                {
                    found = i;
                    break;
                }
            }
            if (found != -1)
            {
                s[found] = '#';
                if (check(a, c, s))
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
            else
                cout << "No\n";
        }
        else
            cout << "No\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}