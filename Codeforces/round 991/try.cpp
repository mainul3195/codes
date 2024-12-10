#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n = 100000000;
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        st.insert(n / i);
        // cout << i << " -> " << n / i << "\n";
    }
    cout << st.size() << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}