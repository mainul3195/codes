#include <bits/stdc++.h>
using namespace std;
string s;
long long dp[19][11][2][2];
int cnt = 0;
long long okdone(int i = 0, int prev = 10, int isSmall = 0, int hasStarted = 0)
{
    if (i == s.size())
        return 1;
    if (~dp[i][prev][isSmall][hasStarted])
        return dp[i][prev][isSmall][hasStarted];
    long long res = 0;
    long long low = 0, high = s[i] - '0';
    if (isSmall)
        high = 9;
    for (int pos = low; pos <= high; pos++)
        if ((hasStarted && (pos != prev)) || (!hasStarted))
            res += okdone(i + 1, pos, isSmall || (pos < high), hasStarted || pos);
    return dp[i][prev][isSmall][hasStarted] = res;
}
long long find(long long x)
{
    if (x < 0)
        return 0;
    s = to_string(x);
    memset(dp, -1, sizeof(dp));
    return okdone();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long l, r;
    cin >> l >> r;
    cout << find(r) - find(l - 1) << "\n";
    return 0;
}