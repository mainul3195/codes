#include <bits/stdc++.h>
using namespace std;
long long fib[50];
void solve()
{
    long long n, xf, yf;
    cin >> n >> xf >> yf;
    int x = 0, y = 0;
    int horiz = 1;
    for (int i = n; i > 0; i--)
    {
        if (horiz)
        {
            if (yf > y + fib[i])
                y += fib[i];
            else if (yf < y + fib[i + 1] - fib[i] + 1)
                ;
            else
            {
                cout << "NO\n";
                return;
            }
        }
        else
        {
            if (xf > x + fib[i])
                x += fib[i];
            else if (xf < x + fib[i + 1] - fib[i] + 1)
                ;
            else
            {
                cout << "NO\n";
                return;
            }
        }
        horiz ^= 1;
    }
    cout << "YES\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fib[0] = fib[1] = 1;
    for (int i = 2; i < 50; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}