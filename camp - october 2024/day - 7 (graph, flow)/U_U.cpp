#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> v = {1, 2, 3};
    // for (auto i : v)
    //     cout << i << " ";
    // cout << "\n";
    // next_permutation(v.begin(), v.end());
    // for (auto i : v)
    //     cout << i << " ";
    // cout << "\n";
    vector<vector<pair<int, int>>> al;
    for (int i = 0; i < v.size(); i++)
        for (int j = i + 1; j < v.size(); j++)
        {
            vector<int> mn;
            for (auto el : v)
                if ((el != v[i]) && (el != v[j]))
                    mn.push_back(el);
            // cout << v[i] << " ";
            // for (auto el : mn)
            //     cout << el << "\t" << el << " ";
            // cout << v[j];
            // cout << "\n";
            do
            {
                vector<pair<int, int>> tmp;
                for (int k = 0; k < mn.size(); k++)
                {
                    if (!k)
                        tmp.push_back({v[i], mn[k]});
                    else
                        tmp.push_back({mn[k - 1], mn[k]});
                }
                tmp.push_back({mn.back(), v[j]});
                al.push_back(tmp);
            } while (next_permutation(mn.begin(), mn.end()));
        }
    int cnt = 0;
    for (auto t : al)
    {
        for (auto [a, b] : t)
        {
            cout << a << "," << b << "\t";
            if ((a == 1 && b == 2) || (b == 1 && a == 2))
                cnt++;
        }
        cout << "\n";
    }
    cout << cnt << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}