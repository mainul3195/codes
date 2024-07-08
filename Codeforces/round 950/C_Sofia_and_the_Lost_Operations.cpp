#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    int m;
    cin >> m;
    multiset<int> st;
    vector<int> d;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
        d.push_back(x);
    }
    int last = d.back(), last_count = 0;
    for (auto i : d)
        if (i == last)
            last_count++;

    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
        {
            auto it = st.find(b[i]);
            if (it == st.end())
            {
                cout << "NO\n";
                return;
            }
            st.erase(it);
        }
    int final_count = 0;
    for (auto el : st)
        if (el == last)
            final_count++;
    if (final_count == last_count)
    {
        for (int i = 0; i < n; i++)
            if (a[i] == b[i] && b[i] == last)
            {
                cout << "YES\n";
                return;
            }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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