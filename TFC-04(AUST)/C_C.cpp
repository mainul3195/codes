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
long long inv2, inv3;
// 1 + 2 + 4 + 6 + 9 + 16 + 20 + 25 + ...
long long find(long long n)
{
    long long mx = (n + 2) / 2;
    mx %= Mod;
    return ((((mx * (mx + 1) % Mod) % Mod * ((2 * mx % Mod + 1) % Mod) % Mod * inv3 % Mod - (mx * ((mx + 1) % Mod)) % Mod * inv2 % Mod + Mod) % Mod + (n & 1 ? (mx * mx % Mod + mx) % Mod : 0))) % Mod;
}
long long find_final(long long n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 2;
    n--;
    long long n1 = n / 2;
    long long n2 = n1 + n % 2;
    return find(n1) + find(n2);
}
void solve()
{
    // for (int i = 0; i < 100; i++)
    // {

    //     int d = i / 2;
    //     // if (i % 2 == 0)
    //     cout << i << " -> " << (d * d + 4 * d + 4) / 4 << " " << (((i + 4) / 2) * ((i + 4) / 2)) / 4 << " " << find_final(i) << "\n";
    // }
    // // long long sum = 0;
    // // for (int i = 0; i <= 100; i++)
    // // {
    // //     sum += i * i;
    // //     cout << sum << " " << i * (i + 1) * (2 * i + 1) / 6 << "\n";
    // // }

    // // int sum = 0, d = 1, dc = 0, t = 0;
    // // for (int i = 0; i <= 120; i++)
    // // {
    // //     t += d;
    // //     sum += t;
    // //     dc++;
    // //     if (dc == 2)
    // //     {
    // //         dc = 0;
    // //         d++;
    // //     }
    // //     cout << i << " " << find(i) << " " << sum << "\n";
    // // }

    int n;
    cin >> n;
    while (n--)
    {
        long long x;
        cin >> x;
        cout << find_final(x) % Mod << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inv3 = modInverse(3);
    inv2 = modInverse(2);
    solve();
    return 0;
}