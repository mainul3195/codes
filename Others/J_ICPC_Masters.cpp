#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >>
        n >> k;
    if (n % k == 0)
        cout << n / k << "\n";
    else
        cout << n % k << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}