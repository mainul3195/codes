#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a, b;
    a.push_back(0);
    b.push_back(0);
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    while (q--)
    {
        int d;
        cin >> d;
        if (d == n)
            cout << b.back() << " ";
        else
        {
            int ind = lower_bound(a.begin(), a.end(), d) - a.begin();
            if (a[ind] != d)
                ind--;
            // cout << "ind = " << ind << "\n";
            cout << (d - a[ind]) * (b[ind + 1] - b[ind]) / (a[ind + 1] - a[ind]) + b[ind] << " ";
        }
    }
    cout << "\n";

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