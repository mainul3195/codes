#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k, mul = 1;
    cin >> n >> k;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    for (auto i : v)
        if (2023 % i)
        {
            cout << "NO\n";
            return;
        }
    for (auto i : v)
        mul *= i;
    if (2023 % mul)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i < k; i++)
        cout << 1 << " ";
    cout << 2023 / mul << "\n";
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