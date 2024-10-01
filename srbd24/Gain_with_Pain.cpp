#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int b, l, c, s, a, sets, reps;
    vector<int> v = {2, 2, 2, 1, 3};
    bool ok = 1;
    while (n--)
    {
        for (int i = 0; i < 5; i++)
        {
            int x;
            cin >> x >> sets >> reps;
            if ((x != v[i]) || (sets != 3) || (reps != 10))
                ok = 0;
        }
    }
    if (ok)
        cout << "Consistent\n";
    else
        cout << "Inconsistent\n";
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