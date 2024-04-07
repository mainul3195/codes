#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long ans = 0;
    int n;
    cin >> n;
    long long cur = 0;
    cin >> cur;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        if (x < cur)
            ans += cur - x;
        else
            cur = x;
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