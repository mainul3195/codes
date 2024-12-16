#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

void solve()
{
    ordered_set st;
    int n;
    cin >> n;
    while (n--)
    {
        char c;
        int x;
        cin >> c >> x;
        // cout << c << " " << x << " -> ";
        if (c == 'I')
            st.insert(x);
        else if (c == 'D')
        {
            auto it = st.find(x);
            if (it != st.end())
                st.erase(it);
        }
        else if (c == 'C')
            cout << st.order_of_key(x) << "\n";
        else
        {
            if (x > st.size())
                cout << "invalid\n";
            else
                cout << *(st.find_by_order(x - 1)) << "\n";
        }
        // cout << "\nFull: ";
        // for (int i = 1; i <= st.size(); i++)
        //     cout << *(st.find_by_order(i - 1)) << " ";
        // cout << "\n";
        // for (auto i : st)
        //     cout << i << " ";
        // cout << "\n";
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
