#include <bits/stdc++.h>
using namespace std;
int sp_table[200005][33];
int n, q;
void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> sp_table[i][0];
    for (int k = 1; k < 33; k++)
        for (int i = 1; i <= n; i++)
            sp_table[i][k] = sp_table[sp_table[i][k - 1]][k - 1];
    while (q--)
    {
        long long u, x;
        cin >> u >> x;
        for (int k = 32; k >= 0; k--)
            if (x&(1LL<<k))
                u = sp_table[u][k];
        cout << u << "\n";
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