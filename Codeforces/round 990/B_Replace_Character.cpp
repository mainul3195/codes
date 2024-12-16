#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    set<char> st;
    for (auto c : s)
        st.insert(c);
    if (st.size() == 1)
    {
        cout << s << "\n";
        return;
    }
    int ar[26] = {0};
    for (auto c : s)
        ar[c - 'a']++;
    int mx = -1, mn = 10000000;
    for (int i = 0; i < 26; i++)
    {
        if (ar[i] != 0)
        {
            mx = max(mx, ar[i]);
            mn = min(mn, ar[i]);
        }
    }
    char mx_char, mn_char;
    bool mx_found = 0;
    for (int i = 0; i < 26; i++)
    {
        if ((ar[i] == mx) && !mx_found)
        {
            mx_char = i + 'a';
            mx_found = 1;
            continue;
        }
        if (ar[i] == mn)
            mn_char = i + 'a';
    }
    bool done = 0;
    for (auto c : s)
    {
        if (!done && (c == mn_char))
        {
            done = 1;
            cout << mx_char;
            continue;
        }
        cout << c;
    }
    cout << "\n";
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