#include <bits/stdc++.h>
using namespace std;
struct cust
{
    int cid, l, r;
    bool operator<(const cust &a) const
    {
        return l < a.l || (l == a.l && r < a.r);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<cust> v(n);
    int flg = 0;
    set<int> st;
    for (auto &[c, l, r] : v)
    {
        c = flg++;
        cin >> l >> r;
        st.insert(l);
        st.insert(r);
    }
    flg = 1;
    map<int, int> mp;
    for (auto i : st)
        mp[i] = flg++;
    for (auto &[c, l, r] : v)
        l = mp[l], r = mp[r];
    int mx = st.size() + 5;
    vector<vector<int>> check_in(mx), check_out(mx);
    for (auto [c, l, r] : v)
    {
        check_in[l].push_back(c);
        check_out[r].push_back(c);
    }
    vector<int> ans(n);
    set<int> available_room;
    int room_count = 0;
    int cur_time = 0;
    while (cur_time < mx)
    {
        while (check_in[cur_time].size())
        {
            if (available_room.size())
            {
                ans[check_in[cur_time].back()] = *available_room.begin();
                available_room.erase(available_room.begin());
            }
            else
                ans[check_in[cur_time].back()] = ++room_count;
            check_in[cur_time].pop_back();
        }
        while (check_out[cur_time].size())
        {
            int khali_hoise = ans[check_out[cur_time].back()];
            check_out[cur_time].pop_back();
            available_room.insert(khali_hoise);
        }
        cur_time++;
    }
    cout << room_count << "\n";
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}