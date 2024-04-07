#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<int> st;
    while (n--)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    while (m--)
    {
        int x;
        cin >> x;
        auto it = st.upper_bound(x);
        if (it == st.begin())
            cout << "-1\n";
        else
        {
            it--;
            cout << *it << "\n";
            st.erase(it);
        }
    }
    return 0;
}