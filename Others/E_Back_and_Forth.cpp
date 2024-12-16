#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    for (int i = ty - sy; i; i--)
        cout << "U";
    for (int i = tx - sx; i; i--)
        cout << "R";
    for (int i = ty - sy; i; i--)
        cout << "D";
    for (int i = tx - sx; i; i--)
        cout << "L";
    cout << "L";
    for (int i = ty - sy + 1; i; i--)
        cout << "U";
    for (int i = tx - sx + 1; i; i--)
        cout << "R";
    cout << "D";
    cout << "R";
    for (int i = ty - sy + 1; i; i--)
        cout << "D";
    for (int i = tx - sx + 1; i; i--)
        cout << "L";
    cout << "U\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}