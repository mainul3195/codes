#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int ar[50] = {0};
    for (auto i : v)
    {
        int cnt = 0;
        while (i)
        {
            cnt++;
            i >>= 1;
        }
        ar[cnt]++;
    }
    int mx = 0;
    for (int i = 0; i < 40; i++)
        mx = max(mx, ar[i]);
    cout << mx << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}