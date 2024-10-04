#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a[3];

    while (cin >> a[0] >> a[1] >> a[2] && (a[0] || a[1] || a[2]))
    {
        sort(a, a + 3);
        if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2])
            cout << "right\n";
        else
            cout << "wrong\n";
    }
    return 0;
}