#include <bits/stdc++.h>
using namespace std;
vector<long long> terms;
vector<int> make(long long n)
{
    if (n == -1)
        return {-1};
    if (n == 1)
        return {1};
    if (n == 0)
        return {0};
    bool neg = n < 0;
    if (neg)
        n *= -1;
    long long nxt = *lower_bound(terms.begin(), terms.end(), n);
    int sz = (int)log2(nxt + .5) + 1;
    // cout << sz << " ";
    vector<int> v(sz, 0);
    v[sz - 1] = 1;
    long long need = n - (1LL << (sz - 1));
    // cout << need << " ";
    vector<int> tmp = make(need);
    // cout << "Tmp -> ";
    // for (auto i : tmp)
    //     cout << i << " ";
    // cout << "\n";
    for (int i = 0; i < tmp.size(); i++)
        v[i] = tmp[i];
    if (neg)
        for (auto &i : v)
            i *= -1;
    return v;
}
void solve()
{
    long long n;
    cin >> n;
    vector<int> v = make(n);
    cout << v.size() << "\n";
    for (auto i : v)
        cout << i << " ";
    cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long mul = 1;
    terms.push_back(mul);
    for (int i = 0; i < 33; i++)
    {
        mul <<= 1;
        if (i % 2)
            mul++;
        terms.push_back(mul);
    }
    // for (auto i : terms)
    //     cout << i << "\n";
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}