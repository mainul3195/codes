#include <bits/stdc++.h>
using namespace std;
#define pi (2 * (acos(0.0)))
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int R, n;
    while (cin >> R >> n)
    {
        if (n == 1)
        {
            cout << fixed << setprecision(10) << (double)R << " " << (double)0 << " " << (double)0 << "\n";
            continue;
        }
        double theta = 2 * pi / n;
        double half = theta / 2;
        double r = R * sin(half) / (1 + sin(half));
        // cout << r << "\n";
        double i = .5 * (R - r) * (R - r) * sin(theta) * n - ((pi - theta) * r * r / 2) * n;
        double e = pi * R * R - .5 * (R - r) * (R - r) * sin(theta) * n - ((pi + theta) * r * r / 2) * n;
        cout << fixed << setprecision(10) << r << " " << i << " " << e << "\n";
    }
    return 0;
}