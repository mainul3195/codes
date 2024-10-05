#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<unsigned long long> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    set<long long> st;
    for (auto i : a)
        st.insert(i);
    for (auto i : b)
        st.insert(i);
    map<int, long long> mp1, mp2;
    srand(time(0));
    for (auto i : st)
    {
        mp1[i] = (long long)rand() * rand();
        mp2[i] = (long long)rand() * rand();
    }
    unsigned long long sum1 = 0, sum2 = 0;
    vector<pair<unsigned long long, unsigned long long>> v1, v2;
    v1.push_back({0, 0});
    v2.push_back({0, 0});
    unsigned long long x, y;
    for (auto i : a)
    {
        x = mp1[i];
        y = mp2[i];
        sum1 = (sum1 + x);
        sum2 = (sum2 + y);
        v1.push_back({sum1, sum2});
    }
    sum1 = 0, sum2 = 0;
    for (auto i : b)
    {
        x = mp1[i];
        y = mp2[i];
        sum1 = (sum1 + x);
        sum2 = (sum2 + y);
        v2.push_back({sum1, sum2});
    }
    while (q--)
    {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        pair<unsigned long long, unsigned long long> p1, p2;
        p1 = {(v1[r].first - v1[l - 1].first), (v1[r].second - v1[l - 1].second)};
        p2 = {(v2[R].first - v2[L - 1].first), (v2[R].second - v2[L - 1].second)};
        if (p1 == p2)
            cout << "Yes\n";
        else
            cout << "No\n";
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