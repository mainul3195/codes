#include <bits/stdc++.h>
using namespace std;
vector<int> m = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool leap_year(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
void solve()
{
    int y;
    cin >> y;
    int cur_year = 1970, start_col = 3;
    while (cur_year < y)
    {
        if (leap_year(cur_year))
            m[1] = 29;
        else
            m[1] = 28;
        for (int i = 0; i < 12; i++)
            start_col = (start_col + m[i]) % 7;
        cur_year++;
    }
    int ans = 0;
    for (int i = 0; i < 12; i++)
    {
        if (leap_year(cur_year))
            m[1] = 29;
        else
            m[1] = 28;
        ans += (start_col + m[i] - 1) / 7 + 1;
        start_col = (start_col + m[i]) % 7;
    }
    cout << ans << "\n";

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}