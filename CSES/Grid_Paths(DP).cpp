#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> grid(n);
    for (auto &s : grid)
        cin >> s;
    vector<vector<long long>> dp(n + 3, vector<long long>(n + 3, 0));
    dp[n - 1][n - 1] = grid[n - 1][n - 1] == '*' ? 0 : 1;
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            if (grid[i][j] == '.')
                (dp[i][j] += dp[i][j + 1] + dp[i + 1][j]) %= 1000000007;
    cout << dp[0][0] << "\n";
    return 0;
}