#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        st.erase(st.find(x));
    }
    cout << *st.begin() << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}