#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    for (int k = n; k > 0; k--)
    {
        int cur_inv = 0, i;
        vector<int> to_reduce(n + 2, 0);
        for (i = 0; i < n; i++)
        {
            cur_inv -= to_reduce[i];
            int cur_char = s[i] - '0';
            cur_char ^= (cur_inv % 2);
            if (!cur_char)
            {
                if (i + k > n)
                    break;
                to_reduce[i + k]++;
                cur_inv++;
            }
        }
        if (i == n)
        {
            cout << k << "\n";
            return;
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