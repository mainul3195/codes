#include <bits/stdc++.h>
using namespace std;
long long calc(long long n)
{
    long long sum = 0;
    long long lim = sqrt(n + .5);
    for (long long i = 1; i <= lim; i++)
    {
        long long terms = n / i - (i * i - 1) / i;
        sum += terms * i + terms * (terms - 1) / 2 + (terms - 1) * i;
    }
    return sum;
}
void solve()
{
    long long l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}