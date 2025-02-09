#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int mx_cnt = 0, ans = -1, mx_el = -1;
    for (auto &i : a)
    {
        cin >> i;
        mx_el = max(mx_el, i);
    }
    for (int i = 2; i <= mx_el; i++)
    {
        int cnt = 0;
        for (auto el : a)
            if (el % i == 0)
                cnt++;
        if (cnt >= mx_cnt)
        {
            mx_cnt = cnt;
            ans = i;
        }
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}