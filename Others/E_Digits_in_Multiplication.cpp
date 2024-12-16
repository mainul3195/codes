#include <bits/stdc++.h>
using namespace std;

int nod(long long x)
{
    int d = 0;
    while (x)
    {
        d++;
        x /= 10;
    }
    return d;
}
void solve()
{
    long long n;
    cin >> n;
    long long mid = sqrt(n + .5);
    for (mid; mid > 0; mid--)
        if (n % mid == 0)
        {
            cout << nod(n / mid) << "\n";
            return;
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