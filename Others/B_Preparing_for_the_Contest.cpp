#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = n - k, j = k; j >= 0; j--, i++)
        cout << i << " ";
    for (int i = n - k - 1; i; i--)
        cout << i << " ";
    cout << "\n";

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