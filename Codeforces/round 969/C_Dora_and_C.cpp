#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, a, b;
    cin >> n >> a >> b;
    // cout << n << " " << a << " " << b << "\n";
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    if (n == 1 || (gcd(a, b) == 1))
    {
        cout << "0\n";
        return;
    }
    long long mn = 20000000000LL;
    for (auto i : v)
        mn = min(mn, i);
    for (auto &i : v)
        i -= mn;
    set<long long> st(v.begin(), v.end());
    if (st.size() == 1)
    {
        cout << "0\n";
        return;
    }
    long long g = gcd(a, b);
    while (1)
    {
        long long f, s, l;
        auto itf = st.begin();
        auto its = st.begin();
        its++;
        auto itl = st.end();
        itl--;
        f = *itf;
        s = *its;
        l = *itl;
        long long x = f + (l - f) / g * g;
        if (x != f)
        {
            st.erase(itf);
            st.insert(x);
            continue;
        }
        x = f + (l - f + g - 1) / g * g;
        if (x - l < s - f)
        {
            st.erase(itf);
            st.insert(x);
        }
        else
            break;
    }
    v = vector<long long>(st.begin(), st.end());
    long long ans = v.back() - v[0];
    int lim = v.size();
    for (int i = 0; i < lim; i++)
    {
        ans = min(ans, v[i + lim - 1] - v[i]);
        v.push_back(v[i] + g);
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}