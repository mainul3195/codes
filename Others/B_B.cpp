#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<int> st;
    for (auto i : v)
    {
        int l = 0, r = st.size() - 1, mid, ind = st.size();
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (st[mid] < i)
            {
                ind = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        int a = st.size() - ind;
        cout << a << "\n";
        while (st.size() && st.back() <= i)
            st.pop_back();
        st.push_back(i);
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