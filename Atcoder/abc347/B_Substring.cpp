#include <bits/stdc++.h>
using namespace std;

void solve()
{
    set<string> st;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
            st.insert(s.substr(i, j - i + 1));
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