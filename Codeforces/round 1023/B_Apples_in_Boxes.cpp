#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    int mx = -1, ind;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] > mx)
            mx = v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] == mx)
        {
            v[i]--;
            break;
        }
    }
    mx = -1;
    int mn = 2000000000;
    for (auto i : v)
        mx = max(mx, i), mn = min(mn, i);
    if (mx - mn > k)
    {
        cout << "Jerry\n";
        return;
    }
    long long sum = 1;
    for (auto i : v)
        sum += i;
    if (sum & 1)
        cout << "Tom\n";
    else
        cout << "Jerry\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}