#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b, c, t;
    cin >> a >> b >> c;
    t = c;
    string bin;
    while (c)
    {
        bin += (char)((c % 2) + '0');
        c >>= 1;
    }
    c = t;
    while (bin.size() < 60)
        bin += '0';
    // cout << c << "\n";
    int ones = __builtin_popcountll(c);
    // cout << ones << "\n";
    if ((a + b - ones < 0) || ((a + b - ones) % 2))
    {
        cout << "-1\n";
        return;
    }
    int z = (a + b - ones) / 2;
    int x = a - z;
    int y = b - z;
    // cout << x << " " << y << " " << z << "\n";
    if (x < 0 || y < 0)
    {
        cout << "-1\n";
        return;
    }
    string frst = bin, scnd = bin;
    for (int i = 0; i < bin.size(); i++)
    {
        frst[i] = scnd[i] = '0';
        if (bin[i] == '0')
        {
            if (z)
            {
                frst[i] = scnd[i] = (char)(1 + '0');
                z--;
            }
            continue;
        }
        if (x)
        {
            frst[i] = '1';
            x--;
            continue;
        }
        scnd[i] = '1';
        y--;
    }
    if (x || y || z)
    {
        cout << "-1\n";
        return;
    }
    // cout << bin << "\n"
    //      << frst << "\n"
    //      << scnd << "\n";
    long long mul = 1, p = 0, q = 0;
    for (int i = 0; i < frst.size(); i++)
    {
        if (frst[i] == '1')
            p += mul;
        if (scnd[i] == '1')
            q += mul;
        mul <<= 1;
    }
    cout << p << " " << q << "\n";
    // cout << __builtin_popcountll(p) << " " << __builtin_popcountll(q) << " " << (p ^ q) << "\n";

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}