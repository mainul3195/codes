#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    cout << "? 1 " << n << endl;
    int prev;
    cin >> prev;
    if (prev == 0)
        cout << "! IMPOSSIBLE\n";
    else
    {
        string s;
        for (int i = n - 1; i >= 2; i--)
        {
            cout << "? 1 " << i << endl;
            int x;
            cin >> x;
            if (x == prev)
                s.push_back('0');
            else
            {
                s.push_back('1');
                if (x == 0)
                {
                    for (int j = 0; j < prev; j++)
                        s.push_back('0');
                    int rem = i - prev;
                    for (int j = 0; j < rem; j++)
                        s.push_back('1');
                    reverse(s.begin(), s.end());
                    cout << "! " << s << endl;
                    return;
                }
                prev = x;
            }
        }

        s.push_back('1');
        s.push_back('0');

        reverse(s.begin(), s.end());
        cout << "! " << s << endl;
    }
    return;
}
int32_t main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}