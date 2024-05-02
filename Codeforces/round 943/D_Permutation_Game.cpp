#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, k, pa, pb;
    cin >> n >> k >> pa >> pb;
    vector<int> p(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> va, vb;
    int start = pa;
    do
    {
        va.push_back(a[pa]);
        pa = p[pa];
    } while (pa != start);
    start = pb;
    do
    {
        vb.push_back(a[pb]);
        pb = p[pb];
    } while (pb != start);
    while (va.size() > k)
        va.pop_back();
    while (vb.size() > k)
        vb.pop_back();
    long long sum_a = 0, sum_b = 0, mxa = 0, mxb = 0;
    for (int i = 0; i < va.size(); i++)
    {
        mxa = max(mxa, sum_a + (k - i) * va[i]);
        sum_a += va[i];
    }
    for (int i = 0; i < vb.size(); i++)
    {
        mxb = max(mxb, sum_b + (k - i) * vb[i]);
        sum_b += vb[i];
    }
    if (mxa > mxb)
        cout << "Bodya\n";
    else if (mxa < mxb)
        cout << "Sasha\n";
    else
        cout << "Draw\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}