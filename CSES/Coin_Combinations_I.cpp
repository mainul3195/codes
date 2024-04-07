#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<long long> c(n);
    for (auto &i : c)
        cin >> i;
    vector<long long> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
        for (auto j : c)
            (dp[i] += i - j >= 0 ? dp[i - j] : 0) %= 1000000007;
    cout << dp[x] << "\n";
    return 0;
}