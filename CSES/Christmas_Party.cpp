#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long dp[1000006];
long long find(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (~dp[n])
        return dp[n];
    return dp[n] = (n - 1) * (find(n - 1) + find(n - 2)) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << find(n) << "\n";
    return 0;
}