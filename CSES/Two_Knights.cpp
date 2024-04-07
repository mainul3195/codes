#include <bits/stdc++.h>
using namespace std;
vector<long long> v = {0, 0,
                       6,
                       28,
                       96,
                       252,
                       550,
                       1056,
                       1848};
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i <= 8)
            cout << v[i] << "\n";
        else
        {
            long long sq = i * i;
            cout << (4 * (sq - 3) + 8 * (sq - 4) + (12 + (i - 6) * 4) * (sq - 5) + (i - 4) * 4 * (sq - 7) + (i - 4) * (i - 4) * (sq - 9)) / 2 << "\n";
        }
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