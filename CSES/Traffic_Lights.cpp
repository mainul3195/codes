#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x, n;
    cin >> x >> n;
    multiset<int, greater<int>> st;
    st.insert(x);
    set<int> points = {0, x};
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        auto it = points.lower_bound(p);
        int up = *it;
        it--;
        int down = *it;
        int len = up - down;
        auto it1 = st.lower_bound(len);
        st.erase(it1);
        st.insert(up - p);
        st.insert(p - down);
        cout << *st.begin() << " ";
        points.insert(p);
    }
    cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}