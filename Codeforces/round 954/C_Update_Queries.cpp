#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string a, c;
    cin >> a;
    set<int> st;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    cin >> c;
    sort(c.begin(), c.end());
    int i = 0;
    for (auto ind : st)
        a[ind - 1] = c[i++];
    cout << a << "\n";
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