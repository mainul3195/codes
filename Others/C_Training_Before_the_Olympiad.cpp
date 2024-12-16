#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    long long sum = 0;
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x & 1)
            odd++;
        else
            even++;
        sum += x;
        int red = odd / 3;
        if (odd % 3 == 1 && i)
            red++;
        cout << sum - red << " ";
    }
    cout << "\n";
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