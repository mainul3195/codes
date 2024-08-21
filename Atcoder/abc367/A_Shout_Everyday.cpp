#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int sh, sl, wa;
    cin >> sh >> sl >> wa;
    if (sl < wa)
    {
        if (sh > sl && sh < wa)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    else
    {
        if (sh > sl || sh < wa)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}