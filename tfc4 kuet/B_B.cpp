#include <bits/stdc++.h>
using namespace std;
long long bit[1000006];
long long qr(long long x)
{
    long long ans = 0;
    for (; x > 0; x -= (x & (-x)))
        ans += bit[x];
    return ans;
}
void upd(long long x, long long val)
{
    for (; x <= 1000000; x += (x & (-x)))
        bit[x] += val;
}
// bool cmp(pair<int, int> &a, pair<int, int> &b)
// {

//     return a.first < b.first || (a.first == b.first && a.second > b.second);
//     // return a.first < b.first || (a.first == b.first && a.second < b.second);
// }
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> gifts(n);
    for (auto &[a, b] : gifts)
        cin >> a;
    for (auto &[a, b] : gifts)
        cin >> b;
    sort(gifts.begin(), gifts.end());
    set<int> st;
    for (auto [a, b] : gifts)
        st.insert(a), st.insert(b);
    int s = 1;
    map<int, int> mp;
    for (auto i : st)
        mp[i] = s++;
    for (auto &[a, b] : gifts)
        a = mp[a], b = mp[b];
    long long tot = 0;
    // for (auto [a, b] : gifts)
    //     cout << a << " ";
    // cout << "\n";
    // for (auto [a, b] : gifts)
    //     cout << b << " ";
    // cout << "\n";

    int last = -1;
    for (int i = 0; i < n; i++)
    {
        if (i > last)
        {
            int el = gifts[i].first;
            for (int j = i; j < n; j++)
            {
                if (gifts[j].first == el)
                    upd(gifts[j].second, 1), last = j;
                else
                    break;
            }
        }
        tot += qr(s) - qr(gifts[i].second - 1);
    }
    // for (auto [a, b] : gifts)
    // {
    //     upd(b, 1);
    //     cout << qr(s) - qr(b - 1) << " ";
    //     tot += qr(s) - qr(b - 1);
    // }
    cout << tot << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}