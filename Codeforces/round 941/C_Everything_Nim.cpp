#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    vector<int> v(st.rbegin(), st.rend());
    int prev = 0, turn = 1;

    while (v.size() > 1)
    {
        int cur = v.back();
        v.pop_back();
        if (cur - prev != 1)
            break;
        turn ^= 1;
        prev = cur;
    }
    if (turn == 1)
        cout << "Alice\n";
    else
        cout << "Bob\n";
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