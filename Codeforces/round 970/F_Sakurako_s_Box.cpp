#include <bits/stdc++.h>
using namespace std;
#define Mod 1000000007
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return (b * bigMod(b, p - 1)) % Mod;
    long long T = bigMod(b, p / 2);
    return (T * T) % Mod;
}
long long modInverse(long long n)
{
    return bigMod(n, Mod - 2);
}
void solve()
{
    long long n;
    cin >> n;
    vector<long long> v, cum_sum;
    long long sum = 0;
    cum_sum.push_back(sum);
    for (int i = 0; i < n; i++)
    {
        long long x;
        cum_sum.push_back(sum);
        cin >> x;
        (sum += x) %= Mod;
        v.push_back(x);
    }
    long long up = 0;
    while (v.size())
    {
        (up += (v.back() * cum_sum.back() % Mod)) %= Mod;
        v.pop_back();
        cum_sum.pop_back();
    }
    long long down = n * (n - 1) / 2;
    down %= Mod;
    cout << up * modInverse(down) % Mod << "\n";

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