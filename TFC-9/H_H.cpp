#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int c1 = 0, c2 = 0;
    int prev = 0;
    cin >> prev;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        if (x > prev)
            c1++;
        if (x < prev)
            c2++;
        prev = x;
    }
    cout << c1 << " " << c2 << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}