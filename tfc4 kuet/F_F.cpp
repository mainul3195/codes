#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n), tmp;
    ;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v[i] = x + y + z;
        tmp.push_back(v[i]);
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++)
    {
        int nw = v[i] + 300;
        int tot = tmp.end() - upper_bound(tmp.begin(), tmp.end(), nw);
        if (tot >= k)
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