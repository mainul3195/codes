#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    multiset<long long> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    int ans = 0;
    while (st.size())
    {
        auto it = st.end();
        it--;
        long long num = *it;
        int cnt = 0;
        while (num)
        {
            cnt++;
            num >>= 1;
        }
        num = *it;
        st.erase(it);
        if ((1LL << cnt) < num)
            cnt++;
        for (int i = cnt;; i++)
        {
            long long target = 1LL << i;
            if (target > 2 * num)
                break;
            auto it1 = st.find(target - num);
            if (it1 != st.end())
            {
                ans++;
                st.erase(it1);
                break;
            }
        }
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}