#include <bits/stdc++.h>
using namespace std;
int find_no(int x, int y, int n)
{
    return min({x, y, n - x + 1, n - y + 1});
}
void solve()
{
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    cout << abs(find_no(x1, y1, n) - find_no(x2, y2, n)) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}