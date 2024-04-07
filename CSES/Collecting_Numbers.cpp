#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (st.find(x - 1) == st.end())
            ans++;
        st.insert(x);
    }
    cout << ans << "\n";
    return 0;
}