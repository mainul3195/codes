#include <bits/stdc++.h>
using namespace std;
int calc(vector<int> &v)
{
    int n = v.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (v[i] != 1)
            sum += v[i];
    return max(1, sum);
}
void solve()
{
    int mx = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n <= 2)
    {
        cout << 10 * (s[0] - '0') + s[1] - '0' << "\n";
        return;
    }
    if (n > 3)
        for (auto c : s)
            if (c == '0')
            {
                cout << "0\n";
                return;
            }
    if (n == 3 && (s[0] == '0' || s[2] == '0'))
    {
        cout << "0\n";
        return;
    }
    vector<int> v;
    for (auto c : s)
        v.push_back(c - '0');
    int ans = 100000000;
    for (int i = 1; i < n; i++)
    {
        vector<int> nw;
        for (int j = 0; j < i - 1; j++)
            nw.push_back(v[j]);
        nw.push_back(10 * v[i - 1] + v[i]);
        for (int j = i + 1; j < n; j++)
            nw.push_back(v[j]);
        ans = min(ans, calc(nw));
    }
    cout << ans << "\n";

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