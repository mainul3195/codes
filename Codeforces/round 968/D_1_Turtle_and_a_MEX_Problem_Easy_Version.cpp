#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    long long sm = 0;
    for (int i = 0; i < n; i++)
    {
        v.clear();
        int l;
        cin >> l;
        while (l--)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.rbegin(), v.rend());
        // for (auto j : v)
        //     cout << j << " ";
        // cout << "\n";
        vector<int> tmp;
        int cur = 0;
        while (tmp.size() < 2)
        {
            if (v.size() == 0)
            {
                tmp.push_back(cur);
                cur++;
            }
            else if (v.back() == cur)
            {
                while (v.size() && v.back() == cur)
                    v.pop_back();
                cur++;
            }
            else
            {
                tmp.push_back(cur);
                cur++;
            }
        }
        // for (auto j : tmp)
        //     cout << j << " ";
        // cout << "\n";
        sm = max(sm, (long long)tmp.back());
    }
    // cout << m << " " << sm << "\n";
    if (m <= sm)
        cout << sm * (m + 1) << "\n";
    else
    {
        long long last = m - sm;
        cout << sm * (sm + 1) + sm * last + (last + 1) * last / 2 << "\n";
    }
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