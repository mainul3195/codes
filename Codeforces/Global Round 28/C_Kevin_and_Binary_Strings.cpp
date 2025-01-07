#include <bits/stdc++.h>
using namespace std;
struct nd
{
    string s;
    int l, r;
    bool operator<(const nd &a) const
    {
        return (s > a.s) || ((s == a.s) && (l > a.l)) || ((s == a.s) && (l == a.l) && (r > a.r));
    }
};
void solve()
{
    string s;
    cin >> s;
    int frst = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            frst = i;
            break;
        }
    }
    if (frst == -1)
    {
        cout << 1 << " " << s.size() << " 1 1" << "\n";
        return;
    }
    int frst_zero = 0;
    int n = s.size();
    int l, r;
    vector<nd> v;
    for (int i = 0; i < frst; i++)
    {
        if (s[i] == '1')
        {
            string ss = "";
            // cout << i << " -> ";
            for (int j = frst, k = i; j < n && k < n; j++, k++)
            {
                // cout << s[j] << " " << s[k] << " " << (char)(((s[j] - '0') ^ (s[k] - '0')) + '0');
                ss += (char)(((s[j] - '0') ^ (s[k] - '0')) + '0');
            }
            // cout << "\n";

            l = i;
            r = i + min(n - i - 1, n - frst - 1);
            v.push_back({ss, l, r});
        }
    }
    sort(v.begin(), v.end());
    // cout << v[0].s << "\n";
    // cout << "here\n";
    // for (auto [a, b, c] : v)
    //     cout << a << "\n";
    cout << "1 " << n << " " << v[0].l + 1 << " " << v[0].r + 1 << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}