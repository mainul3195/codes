#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second || (a.second == b.second && a.first < b.first);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    set<int> st;
    for (auto &[a, b] : v)
    {
        cin >> a >> b;
        st.insert(a);
        st.insert(b);
    }
    map<int, int> mp;
    int count = 0;
    for (auto i : st)
        mp[i] = ++count;
    for (auto &[a, b] : v)
        a = mp[a], b = mp[b];
    sort(v.begin(), v.end(), cmp);
    multiset<int> ended;
    int ans = 0;
    for (auto [a, b] : v)
    {
        auto it = ended.upper_bound(a);
        if (it != ended.begin())
        {
            it--;
            ended.erase(it);
        }
        if (ended.size() < k)
        {
            ans++;
            ended.insert(b);
        }
    }
    cout << ans << "\n";
    return 0;
}