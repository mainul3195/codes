#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int cnt = 0;
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
            for (int k = 1; k <= 6; k++)
                if (i + j + k == 11)
                {
                    cout << "r - " << i << " b - " << j << " y - " << k << "\n";
                }
    cout << cnt << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}