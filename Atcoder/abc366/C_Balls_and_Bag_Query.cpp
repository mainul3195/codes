#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    map<int, int> mp;
    int dif = 0;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 3)
            cout << dif << "\n";
        else if (t == 1)
        {
            int x;
            cin >> x;
            mp[x]++;
            if (mp[x] == 1)
                dif++;
        }
        else
        {
            int x;
            cin >> x;
            mp[x]--;
            if (mp[x] == 0)
                dif--;
        }
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