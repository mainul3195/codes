#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    while (1)
    {
        cout << n << " ";
        if (n == 1)
            break;
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;
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