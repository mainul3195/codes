#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    // for (auto i : v)
    //     cout << i << " ";
    // cout << "\n";
    multiset<long long> st;
    for (int i = a; i < b; i++)
        st.insert(v[i]);
    long long ans = -9223372036854775807;
    for (int i = 1; i + a - 1 <= n; i++)
    {
        if (i + b - 1 <= n)
            st.insert(v[i + b - 1]);
        ans = max(ans, *st.rbegin() - v[i - 1]);
        st.erase(st.lower_bound(v[i + a - 1]));
    }
    cout << ans << '\n';
    return 0;
}