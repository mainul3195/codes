#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    if (n == 1)
    {
        if (v[0] >= k)
            cout << k - 1 << "\n";
        else
            cout << k << "\n";
        return;
    }
    set<int> st(v.begin(), v.end());
    vector<int> w(st.begin(), st.end());
    reverse(w.begin(), w.end());
    bool zero = 0;
    if (w.back() == 0)
    {
        w.pop_back();
        zero = !zero;
    }
    if (w.size() == 0)
    {
        cout << k << "\n";
        return;
    }
    else if (w.size() == 1)
    {
        cout << k + (k + w[0] - 1) / w[0] * w[0] - 1 << "\n";
        return;
    }
    else
    {
        
    }

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