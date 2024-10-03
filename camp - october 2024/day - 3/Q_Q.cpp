#include <bits/stdc++.h>
using namespace std;
#define mx 10000007
vector<int> factors[mx];
void sieve()
{
    for (int i = 2; i < mx; i += 2)
        factors[i].push_back(2);

    for (int i = 3; i * i < mx; i += 2)
        if (factors[i].size() == 0)
            for (int j = i; j < mx; j += i)
                factors[j].push_back(i);
    return;
}
void solve()
{
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}