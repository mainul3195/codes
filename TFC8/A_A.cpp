#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
long long n, k;
ordered_set st;
void solve(long long el = n, long long inversion = k)
{
    long long l = 1, r = el, x;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if ((mid - 1) + ((el - 1) * (el - 2) / 2) >= inversion)
        {
            x = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    int val = *(st.find_by_order(x - 1));
    // cout << "X here -> " << x << "\n";
    cout << val;
    st.erase(st.find(val));
    if (el == 1)
    {
        cout << "\n";
        return;
    }
    cout << " ";
    solve(el - 1, inversion - (x - 1));
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while ((cin >> n >> k) && n != -1)
    {
        while (st.size())
            st.erase(st.begin());
        for (int i = 1; i <= n; i++)
            st.insert(i);
        solve();
    }
    return 0;
}