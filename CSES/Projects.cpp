#include <bits/stdc++.h>
using namespace std;
struct nd
{
    long long l, r, w;
    bool operator<(const nd &a) const
    {
        return r < a.r;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, long long>> ans;
    vector<nd> v(n);
    for (auto &[l, r, w] : v)
        cin >> l >> r >> w;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(ans.begin(), ans.end(), (pair<int, long long>){v[i].l, -1});
        long long prev = i ? ans.back().second : 0;
        long long ans2 = v[i].w;
        if (it != ans.begin())
        {
            it--;
            ans2 += (*it).second;
        }
        ans.push_back({v[i].r, max(prev, ans2)});
    }
    cout << ans.back().second << "\n";
    return 0;
}