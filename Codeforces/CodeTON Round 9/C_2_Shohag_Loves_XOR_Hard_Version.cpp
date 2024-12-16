#include <bits/stdc++.h>
using namespace std;
void to_binary(int n)
{
    string s = "";
    while (n)
    {
        s += (n % 2) + '0';
        n /= 2;
    }
    // reverse(s.begin(), s.end());
    cout << s << "\n";
    return;
}
void solve()
{
    // int x = 41;
    // cout << "\t-> ";
    // to_binary(x);
    // for (int i = 2; i <= 2000; i++)
    // {
    //     cout << i << "\t-> ";
    //     to_binary(x * i);
    // }
    for (int i = 16; i <= 100; i++)
        cout << i << " " << (5 ^ i) << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}