#include<bits/stdc++.h>
using namespace std;
vector<long long> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 121, 232, 343, 454, 565, 676, 787, 898, 12321, 23432, 34543, 45654, 56765, 67876, 78987, 1234321, 2345432, 3456543, 4567654, 5678765, 6789876, 123454321, 234565432, 345676543, 456787654, 567898765, 12345654321, 23456765432, 34567876543, 45678987654, 1234567654321, 2345678765432, 3456789876543, 123456787654321, 234567898765432, 12345678987654321};
void solve()
{
    long long l, r, m;
    cin >> l >> r >> m;
    int cnt = 0;
    for(auto i: v)
        if(i>=l && i<=r && i%m == 0)
            cnt++;
    cout << cnt << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
        freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << ++tc << ": ";
        solve();
    }
    return 0;
}