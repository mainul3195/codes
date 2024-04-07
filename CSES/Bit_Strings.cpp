#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return b * bigMod(b, p - 1) % mod;
    long long t = bigMod(b, p / 2);
    return t * t % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << bigMod(2, n) << "\n";
    return 0;
}