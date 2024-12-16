#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
long long find_inversion(int k)
{
    long long ans = 0;
    for (int l = 0; l < n; l += (1 << k))
    {
        int r = l + (1 << k) - 1;
        int zero_count = 0;
        while (r >= l)
        {
            if ((v[r]) & (1 << (k - 1)))
                ans += zero_count;
            else
                zero_count++;
            r--;
        }
    }
    return ans;
}
void sort(int k)
{
    vector<int> tmp;
    for (int l = 0; l < n; l += (1 << k))
    {
        vector<int> v0, v1;
        int r = l + (1 << k) - 1;
        for (int i = l; i <= r; i++)
        {
            if ((v[i]) & (1 << (k - 1)))
                v1.push_back(v[i]);
            else
                v0.push_back(v[i]);
        }
        for (auto i : v0)
            tmp.push_back(i);
        for (auto i : v1)
            tmp.push_back(i);
    }
    v = tmp;
}
void solve()
{
    cin >> n;
    v = vector<int>(n);
    for (auto &i : v)
        cin >> i;
    long long ans = 0, k = log2(n + .5);
    long long xr = 0;
    // for (int b = log2(n + .5) - 1; b >= 0; b--)
    // {
    //     for (auto i : v)
    //         cout << !!(i & (1 << b)) << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    // sort(4);
    // for (int b = log2(n + .5) - 1; b >= 0; b--)
    // {
    //     for (auto i : v)
    //         cout << !!(i & (1 << b)) << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
    // sort(3);
    // for (int b = log2(n + .5) - 1; b >= 0; b--)
    // {
    //     for (auto i : v)
    //         cout << !!(i & (1 << b)) << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
    for (; k > 0; k--)
    {
        long long in1 = find_inversion(k);
        for (auto &i : v)
            i ^= (1LL << (k - 1));
        long long in2 = find_inversion(k);
        if (in1 < in2)
        {
            ans += in1;
            for (auto &i : v)
                i ^= (1LL << (k - 1));
        }
        else
            ans += in2, xr ^= (1 << (k - 1));
        sort(k);
        // for (int b = log2(n + .5) - 1; b >= 0; b--)
        // {
        //     for (auto i : v)
        //         cout << !!(i & (1 << b)) << " ";
        //     cout << "\n";
        // }
        // cout << "\n";
    }
    if (xr)
        ans++;
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