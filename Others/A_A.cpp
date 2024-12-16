#include <bits/stdc++.h>
using namespace std;

void solve()
{
    double d;
    cin >> d;
    long long a = d * 1000 * 5280 / 4854;
    long long b = d * 10000 * 5280 / 4854;
    if (b % 10 >= 5)
        a++;
    cout << a << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}