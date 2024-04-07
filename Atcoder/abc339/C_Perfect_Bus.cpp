#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    long long tot = 0;
    cin >> n;
    long long mn = 20000000000000000LL;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        tot += x;
        mn = min(mn, tot);
    }
    if (mn < 0)
        tot += -mn;
    cout << tot << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}