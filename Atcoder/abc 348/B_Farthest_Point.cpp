#include <bits/stdc++.h>
using namespace std;
long long dis(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &[a, b] : v)
        cin >> a >> b;
    for (int i = 0; i < n; i++)
    {
        int ind = 0;
        long long cur = 0;
        for (int j = 0; j < n; j++)
        {
            long long tmp = dis(v[i].first, v[i].second, v[j].first, v[j].second);
            // cout << i << " " << j << " " << tmp << "\n";
            if (tmp > cur)
            {
                cur = tmp;
                ind = j + 1;
            }
        }
        cout << ind << "\n";
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