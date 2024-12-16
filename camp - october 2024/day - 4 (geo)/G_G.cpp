#include <bits/stdc++.h>
using namespace std;
#define int long long
double find_angle(int x, int y, int a, int c)
{
    return atan2(y - c, x - a);
}
double rad_to_deg(double rad)
{
    return rad * 180 / (2 * acos(0.0));
}
int n;
long long find_ans(vector<tuple<int, int, int>> &v, int x, int y, int i)
{
    vector<tuple<double, double, int>> segs;
    for (int j = 0; j < n; j++)
        if (i != j)
        {
            auto [a, b, c] = v[j];
            if (c > y)
                segs.push_back({rad_to_deg(find_angle(x, y, b, c)), rad_to_deg(find_angle(x, y, a, c)), b - a});
            else if (c < y)
                segs.push_back({rad_to_deg(find_angle(a, c, x, y)), rad_to_deg(find_angle(b, c, x, y)), b - a});
        }
    // for (auto &[a, b, c] : segs)
    //     cout << a << " " << b << " " << c << "\n";

    sort(segs.begin(), segs.end());
    multiset<pair<double, int>> st;
    long long ans = 0, finl = 0;
    for (auto [a, b, c] : segs)
    {
        while (st.size() && (*st.begin()).first < a)
        {
            ans -= (*st.begin()).second;
            st.erase(st.begin());
        }
        ans += c;
        finl = max(ans, finl);
        st.insert({b, c});
    }
    return finl;
}
void solve()
{
    cin >> n;
    vector<tuple<int, int, int>> v(n);
    for (auto &[a, b, c] : v)
    {
        cin >> a >> b >> c;
        if (a > b)
            swap(a, b);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto [x1, x2, y] = v[i];
        ans = max({ans, find_ans(v, x1, y, i) + x2 - x1, find_ans(v, x2, y, i) + x2 - x1});
        // exit(0);
    }
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}