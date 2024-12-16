#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<long long> a;
vector<vector<int>> qr;
vector<long long> c, d;
void solve()
{
    cin >> n >> q;
    a = vector<long long>(n + 1, 0);
    int lim = sqrt(n + .5);
    qr = vector<vector<int>>(lim + 1);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x > lim)
        {
            for (int j = y; j <= n; j += x)
                a[j]++;
        }
        else
            qr[x].push_back(y);
    }
    for (int i = 1; i <= lim; i++)
        if (qr[i].size())
        {
            c = d = vector<long long>(n + 1, 0);
            for (auto j : qr[i])
                c[j]++;
            for (int j = 1; j <= n; j++)
                d[j] = c[j] + d[max(0, j - i)];
            for (int i = 1; i <= n; i++)
                a[i] += d[i];
        }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}