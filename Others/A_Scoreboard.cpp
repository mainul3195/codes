#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long a = 0, b = 0;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        a += x;
        b += y;
    }
    if (a > b)
        cout << "Takahashi\n";
    else if (b > a)
        cout << "Aoki\n";
    else
        cout << "Draw\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}