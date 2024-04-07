#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> dp(n + 1, 2000000000);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        vector<int> v;
        while (tmp)
        {
            v.push_back(tmp % 10);
            tmp /= 10;
        }
        for (auto j : v)
            dp[i] = min(dp[i], i - j >= 0 ? dp[i - j] + 1 : 2000000000);
    }
    cout << dp[n] << "\n";
    return 0;
}