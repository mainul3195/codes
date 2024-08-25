#include <bits/stdc++.h>
using namespace std;
long long n, k;
int lim;
vector<vector<int>> spt;
void solve()
{
    cin >> n >> k;
    lim = min(63, (int)(log2(k + 3) + .1));
    spt = vector<vector<int>>(n + 1, vector<int>(lim + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        spt[i][0] = p;
    }
    for (int j = 1; j <= lim; j++)
    {
        for (int i = 1; i <= n; i++)
            spt[i][j] = spt[spt[i][j - 1]][j - 1];
    }
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    for (int i = 1; i <= n; i++)
    {
        int cur = i;
        long long rem = k;
        for (int j = lim; j >= 0; j--)
        {
            if ((1LL << j) <= rem)
            {
                cur = spt[cur][j];
                rem -= (1LL << j);
            }
        }
        cout << a[cur - 1] << " ";
    }
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}