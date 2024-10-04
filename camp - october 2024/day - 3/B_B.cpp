#include <bits/stdc++.h>
using namespace std;
int f(int n)
{
    if (n == 1)
        return 0;
    int cnt = 0;
    int tmp = n;
    while (tmp)
    {
        if (tmp & 1)
            cnt++;
        tmp >>= 1;
    }
    return f(cnt) + 1;
}
void solve()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << i << " -> ";
        for (int j = 1; j <= 1000000; j++)
        {
            if (f(j) == i)
            {
                cout << j;
                break;
            }
        }
        cout << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}