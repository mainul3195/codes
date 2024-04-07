#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<long long> v(n);
    map<long long, pair<int, int>> mp;
    for (auto &a : v)
        cin >> a;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long sum = v[i] + v[j];
            if (mp.count(x - sum))
            {
                cout << mp[x - sum].first + 1 << " " << mp[x - sum].second + 1 << " " << i + 1 << " " << j + 1 << "\n";
                return 0;
            }
        }
        for (int k = 0; k < i; k++)
            mp[v[k] + v[i]] = {k, i};
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}