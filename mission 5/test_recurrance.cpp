#include <bits/stdc++.h>
using namespace std;

void solve()
{
    for(int i = 0; i<8; i++)
    {
        int x;
        cin >> x;
        cout << "v[0][" << i << "] = " << x << ";\n";
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