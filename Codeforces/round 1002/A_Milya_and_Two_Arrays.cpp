#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    set<int> sta, stb;
    for (auto &i : a)
    {
        cin >> i;
        sta.insert(i);
    }
    for (auto &i : b)
    {
        cin >> i;
        stb.insert(i);
    }
    if (sta.size() >= 3 || stb.size() >= 3)
    {
        cout << "YES\n";
        return;
    }
    if (sta.size() == 1 || stb.size() == 1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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