#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    set<int> st;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
        st.insert(i);
    }
    if (st.size() == 1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (st.size() == 2)
    {
        if (v[0] == v[1])
        {
            cout << "B";
            for (int i = 1; i < n; i++)
                cout << "R";
            cout << "\n";
            return;
        }
        else
        {
            for (int i = 1; i < n; i++)
                cout << "R";
            cout << "B\n";
            return;
        }
    }
    else
    {
        cout << "B";
        for (int i = 1; i < n; i++)
            cout << "R";
        cout << "\n";
        return;
    }
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