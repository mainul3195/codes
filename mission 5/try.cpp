#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int h, c, t;
        cin >> h >> c >> t;

        // Edge cases
        if (t == h)
        {
            cout << 1 << '\n';
            continue;
        }
        if (t * 1.0 <= (c + h) / 2.0)
        {
            cout << 2 << '\n';
            continue;
        }

        int l = 1, r = 1e6;
        int ans = 1;
        double md = abs(h - t);

        while (l <= r)
        {
            int m = (l + r) / 2;
            double avg = (1LL * m * h + (m - 1) * c) / (2.0 * m - 1);
            double diff = abs(avg - t);

            if (diff < md)
            {
                md = diff;
                ans = 2 * m - 1;
            }

            if (avg < t)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
