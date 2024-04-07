#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    multiset<int> st;
    int count = 0;
    for (auto i : v)
    {
        auto it = st.upper_bound(i);
        if (it == st.end())
            count++;
        else
            st.erase(it);
        st.insert(i);
    }
    cout << count << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}