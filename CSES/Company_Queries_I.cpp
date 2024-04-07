#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<vector<int>> sp_table;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    // cout << n << " " << q << "\n";
    sp_table = vector<vector<int>>(n + 1, vector<int>(log2(n) + 2, -1));
    for (int i = 2; i <= n; i++)
        cin >> sp_table[i][0];
    int lim = log2(n) + 1;
    for (int i = 1; i <= lim; i++)
        for (int j = 2; j <= n; j++)
            if (sp_table[j][i - 1] != -1)
                sp_table[j][i] = sp_table[sp_table[j][i - 1]][i - 1];
    while (q--)
    {
        int u, l;
        cin >> u >> l;
        for (int i = lim; i >= 0; i--)
            if ((1LL << i) <= l)
            {
                u = sp_table[u][i];
                if (u == -1)
                    break;
                l -= (1LL << i);
            }
        cout << u << "\n";
    }
    return 0;
}