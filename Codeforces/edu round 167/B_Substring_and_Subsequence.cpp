#include <bits/stdc++.h>
using namespace std;
string a, b;
void solve()
{
    cin >> a >> b;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
            i++, j++;
        else
            i++;
    }
    if (j == b.size())
    {
        cout << a.size() << "\n";
        return;
    }
    int mn = 10000000;
    for (i = 0; i < b.size(); i++)
    {
        int mis = 0;
        int k = i;
        for (j = 0; j < a.size(); j++)
        {
            if (k == b.size() || (a[j] != b[k]))
            {
                mis++;
                // cout << j << " " << k << "\n";
            }
            else
                k++;
        }
        // cout << i << " -> " << mis << "\n";
        mn = min(mn, mis);
    }
    // cout << mn << "\n";
    cout << b.size() + mn << "\n";
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