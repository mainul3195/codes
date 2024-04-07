#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &[a, b] : v)
        cin >> a >> b;
    set<int> st;
    map<int, int> enter, leave;
    for (auto [a, b] : v)
    {
        enter[a]++;
        leave[b]++;
        st.insert(a);
        st.insert(b);
    }
    int cur = 0, mx = -1;
    for (auto i : st)
    {
        cur += enter[i] - leave[i];
        mx = max(mx, cur);
    }
    cout << mx << "\n";
    return 0;
}