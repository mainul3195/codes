#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
void solve()
{
    cin >> n >> m;
    v = vector<int>(m);
    for (auto &i : v)
        cin >> i;
    int mx = -1;
    for (auto i : v)
        mx = max(mx, i);
    int lim = n * mx;
    vector<int> pos(n * mx + 100, 0);
    pos[0] = 1;
    for (int j = 0; j < n; j++)
    {
        vector<int> tmp(n * mx + 100, 0);
        for (auto i : v)
            for (int start = lim; start >= 0; start--)
            {
                // if (i == 3 && start == 0)
                //     cout << pos[start] << " ok\n";
                if (pos[start] == 1)
                    tmp[start + i] = 1;
            }
        pos = tmp;
    }
    vector<int> all;
    for (int i = 1; i <= lim; i++)
        if (pos[i])
            all.push_back(i);
    int q;
    cin >> q;
    // for (auto i : all)
    //     cout << i << "\n";
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int a = lower_bound(all.begin(), all.end(), l) - all.begin();
        int b = upper_bound(all.begin(), all.end(), r) - all.begin() - 1;

        if (a > b)
            cout << "No\n";
        else
            cout << "Yes\n";
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