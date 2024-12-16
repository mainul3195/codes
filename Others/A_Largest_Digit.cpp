#include <bits/stdc++.h>
using namespace std;
int largest_digit(int n)
{
    int x = 0;
    while (n)
    {
        x = max(x, n % 10);
        n /= 10;
    }
    return x;
}
void solve()
{
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int mx = 0;
    for (int i = l1; i <= r1 && i <= l1 + 10; i++)
        for (int j = l2; j <= r2 && j <= l2 + 10; j++)
            mx = max(mx, largest_digit(i + j));
    cout << mx << "\n";
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