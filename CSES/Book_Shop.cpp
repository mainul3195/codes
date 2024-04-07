#include <bits/stdc++.h>
using namespace std;
vector<long long> price, pages, dp1, dp2;
int n, x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    price = pages = vector<long long>(n);
    for (auto &i : price)
        cin >> i;
    for (auto &i : pages)
        cin >> i;
    dp1 = vector<long long>(x + 2, 0);
    dp2 = vector<long long>(x + 2, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = price[i]; j <= x; j++)
            dp2[j] = max({dp1[j], dp1[j - 1], dp1[j - price[i]] + pages[i]});
        dp1 = dp2;
    }
    cout << dp1[x] << "\n";
    return 0;
}