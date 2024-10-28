// #include <bits/stdc++.h>
// using namespace std;

// vector<int> segtree, a, suffix_sum;
// int n;
// void build(int node = 1, int start = 0, int end = n - 1)
// {
//     if (start == end)
//     {
//         segtree[node] = suffix_sum[start];
//         return;
//     }
//     int mid = (start + end) / 2;
//     build(2 * node, start, mid);
//     build(2 * node + 1, mid + 1, end);
//     segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
//     return;
// }
// int query(int l, int r, int node = 1, int start = 0, int end = n - 1)
// {
//     if (start > r || end < l)
//         return 0;
//     if (start >= l && end <= r)
//         return segtree[node];
//     int mid = (start + end) / 2;
//     int left = query(l, r, 2 * node, start, mid);
//     int right = query(l, r, 2 * node + 1, mid + 1, end);
//     return max(left, right);
// }
// void solve()
// {
//     cin >> n;
//     segtree.resize(4 * n, 0);
//     a = vector<int>(n);
//     for (auto &i : a)
//         cin >> i;
//     vector<int> pref_sum(n, 0);
//     suffix_sum = vector<int>(n, 0);
//     pref_sum[0] = a[0];
//     for (int i = 1; i < n; i++)
//         pref_sum[i] = pref_sum[i - 1] + a[i];
//     suffix_sum[n - 1] = a[n - 1];
//     for (int i = n - 2; i >= 0; i--)
//         suffix_sum[i] = suffix_sum[i + 1] + a[i];
//     build();
//     long long ans = 0;

//     return;
// }
// int32_t main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    long long prefix_sum = 0, kadane_sum = 0, ans = a[0];
    for (int i = 0; i < n; i++)
    {
        prefix_sum += a[i];
        ans = max(ans, prefix_sum + kadane_sum);
        kadane_sum += a[i];
        if (kadane_sum < 0)
            kadane_sum = 0;
    }
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}