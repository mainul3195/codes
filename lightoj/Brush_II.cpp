#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, w;
    cin >> n >> w;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        st.insert(y);
    }
    vector<int> v(st.begin(), st.end());
    int last = -2000000000, cnt = 0;
    while (last < v.back())
    {
        int val = *upper_bound(v.begin(), v.end(), last);
        last = val + w;
        cnt++;
    }
    cout << cnt << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}