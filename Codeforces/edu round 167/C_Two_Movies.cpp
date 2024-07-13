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

    int tota = 0, totb = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] == 0 || a[i] == -1) && b[i] == 1)
            totb++;
        else if (a[i] == 1 && (b[i] == 0 || b[i] == -1))
            tota++;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i] && a[i] == 1)
        {
            if (tota > totb)
                totb++;
            else
                tota++;
        }
        if (a[i] == b[i] && a[i] == -1)
        {
            if (tota > totb)
                tota--;
            else
                totb--;
        }
    }
    cout << min(tota, totb) << "\n";
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