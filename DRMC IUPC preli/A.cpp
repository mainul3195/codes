#include <bits/stdc++.h>
using namespace std;
void solve()
{
    vector<int> v(100);
    v[0] = 1;
    v[1] = 1;
    for (int i = 2; i < 100; i++)
        v[i] = !((v[i / 2] == 1) && (i % 2 == 1));
    for (int i = 0; i < 100; i++)
        cout << i << " -> " << v[i] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}