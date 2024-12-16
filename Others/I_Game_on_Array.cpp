#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (n == 1)
    {
        if (a[0] == 1)
            cout << "Bob\n";
        else
            cout << "Alice\n";
        return;
    }
    if (n == 2)
    {
        if (sum & 1)
            cout << "Bob\n";
        else
        {
            if ((a[0] & 1) == ((sum / 2) & 1))
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }
        return;
    }
    if (n == 3)
    {
        if (sum & 1)
            cout << "Bob\n";
        else
        {
            if (
                (a[0] == 2 && a[1] == 1 && a[2] == 1) ||
                (a[0] == 1 && a[1] == 1 && a[2] == 2))
                cout << "Alice\n";
            else
                cout << "Bob\n";
            return;
        }
    }
    cout << "Bob\n";
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
