#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        if (n <= 2)
        {
            cout << "0\n";
            continue;
        }
        int a = v[0], b, i;
        for (i = 1; i < n; i++)
        {
            if (v[i] > a)
            {
                b = v[i];
                break;
            }
            a = v[i];
        }
        int ans = 0;
        for (i++; i < n; i++)
        {
            if (a > b)
                a ^= b ^= a ^= b;
            if (v[i] > b)
            {
                ans++;
                a = v[i];
            }
            else if (v[i] <= a)
                a = v[i];
            else
                b = v[i];
        }
        cout << ans << "\n";
    }
    return 0;
}