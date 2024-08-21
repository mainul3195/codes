#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &s : v)
        cin >> s;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        while (cur > v[i].size())
            v[i].push_back('*');
        cur = max(cur, (int)v[i].size());
    }
    for (int i = 0; i < cur; i++)
    {
        for (int j = n - 1; j >= 0; j--)
            if (v[j].size() - 1 >= i)
                cout << v[j][i];
        cout << "\n";
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