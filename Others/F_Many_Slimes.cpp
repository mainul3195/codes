#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int val[1 << (n + 1)];
    vector<int> s(1 << n);
    for (auto &i : s)
        cin >> i;
    sort(s.rbegin(), s.rend());
    vector<int> v;
    int lim = 1 << (n + 1);
    v.push_back(1);
    int ind = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int cur = v[i];
        while (cur < lim)
        {
            if (2 * cur + 1 < lim)
                v.push_back(2 * cur + 1);
            cur <<= 1;
        }
    }
    for(auto i: v)
        cout << i << " ";
        cout << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
        {
            if (val[v[i] / 2] == s[i])
            {
                cout << "No\n";
                return;
            }
        }
        int cur = v[i];
        int value = s[i];
        while (cur < lim)
        {
            val[cur] = value;
            cur <<= 1;
        }
    }
    cout << "Yes\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}