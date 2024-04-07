#include <bits/stdc++.h>
using namespace std;
int num[1000006];
void solve()
{
    int n;
    cin >> n;
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        num[x]++;
        mx = max(mx, x);
    }
    for (int i = mx; i >= 1; i--)
    {
        int tot = 0;
        for (int j = i; j <= mx; j += i)
            tot += num[j];
        if (tot >= 2)
        {
            cout << i << "\n";
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}