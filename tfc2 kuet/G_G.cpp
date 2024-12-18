#include <bits/stdc++.h>
using namespace std;
int n, q, lim;
int sparse_table[200005][30];
void solve()
{
    cin >> n >> q;
    lim = 29;
    for (int i = 1; i <= n; i++)
    {
        int to;
        cin >> to;
        sparse_table[i][0] = to;
    }
    for (int k = 1; k <= lim; k++)
        for (int i = 1; i <= n; i++)
            sparse_table[i][k] = sparse_table[sparse_table[i][k - 1]][k - 1];
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        int mul = 1 << lim;
        for (int i = lim; i >= 0 && k > 0; i--, mul >>= 1)
        {
            long long jmp = mul;
            if (jmp <= k)
            {
                k -= jmp;
                x = sparse_table[x][i];
            }
        }
        cout << x << "\n";
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