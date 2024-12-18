#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, a, b;
    cin >> n >> a >> b;
    cout << min(n * a, b) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}