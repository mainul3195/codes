#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector<long long> dp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dp = vector<long long>(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 6; j++)
            (dp[i] += i - j >= 0 ? dp[i - j] : 0) %= mod;
    cout << dp[n];
    return 0;
}