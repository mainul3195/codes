#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    multiset<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (st.empty())
        {
            st.insert(x);
            continue;
        }
        auto it = st.lower_bound(x);
        if (it != st.begin())
        {
            it--;
            st.erase(it);
        }
        st.insert(x);
    }
    cout << st.size() << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}