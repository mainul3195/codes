#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
void toh(int n, int a, int b, int c)
{
    if (n == 1)
    {
        v.push_back({a, c});
        return;
    }
    toh(n - 1, a, c, b);
    v.push_back({a, c});
    toh(n - 1, b, a, c);
    return;
}
void solve()
{
    int n;
    cin >> n;
    toh(n, 1, 2, 3);
    cout << v.size() << "\n";
    for (auto [a, b] : v)
        cout << a << " " << b << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}