#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 2)
        cout << "1 1\n1 2\n";
    else if (n == 3)
        cout << "2 1\n2 3\n3 1\n";
    else if (n == 4)
        cout << "1 1\n1 3\n4 3\n4 4\n";
    else
    {
        cout << n << " " << n << "\n1 1\n1 2\n1 3\n";
        int done = 4;
        int rem = n - done;
        if (rem & 1)
        {
            int u = rem / 2;
            int d = u + 1;
            int x = 1, y = n - 1;
            while (u--)
            {
                cout << x << " " << y << "\n";
                y -= 2;
            }
            x = 2, y = n;
            while (d--)
            {
                cout << x << " " << y << "\n";
                x += 2;
            }
        }
        else
        {
            int u  = rem / 2;
            int d = u;
            u--, d++;
            int x = 1, y = n - 2;
            while (u--)
            {
                cout << x << " " << y << "\n";
                y -= 2;
            }
            x = 1, y = n;
            while (d--)
            {
                cout << x << " " << y << "\n";
                x += 2;
            }
        }
    }

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