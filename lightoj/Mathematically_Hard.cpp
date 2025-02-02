#include <bits/stdc++.h>
using namespace std;
vector<unsigned long long> phi;
#define lim 5000006
void makephi()
{
    phi = vector<unsigned long long>(lim, 0);
    for (int i = 0; i < lim; i++)
        phi[i] = i;
    for (int i = 2; i < lim; i++)
        if (phi[i] == i)
            for (int j = i; j < lim; j += i)
                phi[j] -= phi[j] / i;
    for (int i = 0; i < lim; i++)
        phi[i] *= phi[i];
    for (int i = 1; i < lim; i++)
        phi[i] += phi[i - 1];
    return;
}
void solve()
{
    int l, r;
    cin >> l >> r;
    if (l > r)
        swap(l, r);
    cout << phi[r] - phi[l - 1] << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    makephi();
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}