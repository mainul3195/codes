#include <bits/stdc++.h>
using namespace std;
#define lim 10000005
vector<long long> spf(lim + 1);
void smallest_pf()
{
    for (long long i = 2; i <= lim; i += 2)
        spf[i] = 2;
    for (long long i = 3; i * i <= lim; i += 2)
        if (!spf[i])
            for (long long j = i; j <= lim; j += 2 * i)
                spf[j] = i;
    for (int i = 3; i <= lim; i += 2)
        if (!spf[i])
            spf[i] = i;
    return;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int g = 0;
    for (auto i : v)
        g = gcd(g, i);
    if (g > 1)
    {
        cout << "not coprime\n";
        return;
    }
    map<int, int> found;
    // bool pairwise = 1;
    for (auto i : v)
    {
        while (i > 1)
        {
            int pf = spf[i];
            if (found.find(pf) != found.end())
            {
                cout << "setwise coprime\n";
                return;
            }
            while (i % pf == 0)
                i /= pf;
            found[pf] = 1;
        }
    }
    cout << "pairwise coprime\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    smallest_pf();
    solve();
    return 0;
}