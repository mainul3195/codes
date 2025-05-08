#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int mx = -1, ind;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x > mx)
        {
            mx = x;
            ind = i;
        }
        st.insert(x);
    }
    if (st.size() == 1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            if (i == ind)
                cout << "2 ";
            else
                cout << "1 ";
        }
        cout << "\n";
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
    {
        solve();
    }
    return 0;
}