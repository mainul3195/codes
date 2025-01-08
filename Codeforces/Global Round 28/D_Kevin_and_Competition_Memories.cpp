#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> rating(n), dif(m);
    for (auto &i : rating)
        cin >> i;
    for (auto &i : dif)
        cin >> i;
    int me = rating[0];
    sort(rating.begin(), rating.end());
    sort(dif.begin(), dif.end());
    // cout << "rating -> ";
    // for (auto i : rating)
    //     cout << i << " ";
    // cout << "\n";
    // cout << "dif -> ";
    // for (auto i : dif)
    //     cout << i << " ";
    // cout << "\n";
    vector<int> pos(m);
    for (int i = 0; i < m; i++)
    {
        auto it = lower_bound(rating.begin(), rating.end(), dif[i]);
        if (it == rating.end())
            pos[i] = 1;
        else
        {
            if (*it <= me)
                pos[i] = 1;
            else
                pos[i] = rating.end() - it + 1;
        }
    }
    sort(pos.begin(), pos.end());
    // cout << "pos -> ";
    // for (auto i : pos)
    //     cout << i << " ";
    // cout << "\n";
    for (int i = 1; i <= m; i++)
    {
        long long sum = 0;
        for (int j = i - 1; j < m; j += i)
            sum += pos[j];
        cout << sum << " ";
    }
    cout << "\n";
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