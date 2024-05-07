#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    if (v[0] == v[1] && v[1] == v[2] && v[2] == 0)
        cout << "YES\n";
    else
    {
        if (v[0] == 0)
        {
            map<int, int> mp;
            for (int i = 1; i < n; i++)
                mp[i] = 1;
            for (int i = 1; i <= n; i++)
                if (v[i] && mp[v[i]] && mp[-v[i]])
                {
                    cout << "YES\n";
                    return;
                }
        }
        
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}