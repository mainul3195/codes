#include <bits/stdc++.h>
using namespace std;
vector<long long> c;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    c = vector<long long>(n);
    for (auto &i : c)
        cin >> i;
    vector<long long> dp(x + 1, 2000000000);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
        for (auto j : c)
            dp[i] = min(dp[i], i - j >= 0 ? dp[i - j] + 1 : 2000000000);

    cout << (dp[x] >= 2000000000 ? -1 : dp[x]) << "\n";
    return 0;
}