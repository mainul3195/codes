#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector<vector<long long>> dp;
vector<vector<int>> previous = {
    {},
    {1, 2, 4},
    {1, 2, 4},
    {3, 5, 6, 7, 8},
    {3, 5, 6, 7, 8},
    {1, 2, 4},
    {3, 5, 6, 7, 8},
    {3, 5, 6, 7, 8},
    {3, 5, 6, 7, 8}};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dp = vector<vector<long long>>(1000006, vector<long long>(9, 0));
    for (int i = 1; i <= 8; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= 1000000; i++)
        for (int j = 1; j <= 8; j++)
            for (auto k : previous[j])
                (dp[i][j] += dp[i - 1][k]) %= mod;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (dp[n][2] + dp[n][4]) % mod << "\n";
    }
    return 0;
}