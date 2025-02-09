#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int sum, lim;
    cin >> sum >> lim;
    int last = 1 << (int)(log2(sum + .5));
    set<int> st;
    // cout << last << "\n";
    for (int i = last; sum && (i > 0); i >>= 1)
    {
        // cout << i << " ";
        for (int j = i; (sum >= i) && (j <= lim); j += 2 * i)
            if (st.find(j) == st.end())
            {
                st.insert(j);
                sum -= i;
                if (!sum)
                    break;
            }
    }
    if (sum)
        cout << "-1\n";
    else
    {
        cout << st.size() << "\n";
        for (auto i : st)
            cout << i << " ";
        cout << "\n";
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