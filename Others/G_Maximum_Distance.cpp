#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = 0, k = i;
        int tmp = 0;
        while (k < n)
        {
            tmp += a[k] != b[j];
            k++, j++;
        }
        ans = max(ans, tmp);
        tmp = 0;
        j = 0, k = i;
        while (k < n)
        {
            tmp += a[j] != b[k];
            k++, j++;
        }
        ans = max(ans, tmp);
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}