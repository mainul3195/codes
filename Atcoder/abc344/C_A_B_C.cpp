#include <bits/stdc++.h>
using namespace std;
vector<int> a, b, c;
void solve()
{
    int n, m, l, q;
    cin >> n;
    a = vector<int>(n);
    for (auto &i : a)
        cin >> i;
    cin >> m;
    b = vector<int>(m);
    for (auto &i : b)
        cin >> i;
    cin >> l;
    c = vector<int>(l);
    for (auto &i : c)
        cin >> i;
    set<int> st;
    for (auto i : a)
        for (auto j : b)
            for (auto k : c)
                st.insert(i + j + k);
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (st.find(x) != st.end())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}