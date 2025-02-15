#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a11, a12, a21, a22, b11, b12, b21, b22;
    cin >> a11 >> a12 >> a21 >> a22 >> b11 >> b12 >> b21 >> b22;
    cout << a11 * b11 + a12 * b21 << " " << a11 * b12 + a12 * b22 << "\n"
         << a21 * b11 + a22 * b21 << " " << a21 * b12 + a22 * b22 << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}