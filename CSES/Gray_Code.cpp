#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++)
        s += '0';
    vector<string> v((1 << n), s);
    int len = v.size();
    for (int i = 1; i < len; i++)
    {
        v[i] = v[i - 1];
        for (int j = v[i].size() - 1; j >= 0; j--)
        {
            if (v[i][j] == '0')
            {
                v[i][j] = '1';
                break;
            }
            v[i][j] = '0';
        }
    }
    for (auto &str : v)
    {
        for (int j = str.size() - 1; j; j--)
        {
            if (str[j] != str[j - 1])
                str[j] = '1';
            else
                str[j] = '0';
        }
    }
    for (auto i : v)
        cout << i << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
