#include <bits/stdc++.h>
using namespace std;
vector<unsigned long long> digit_cum_sum, no;
void solve()
{
    long long n;
    cin >> n;
    int group_no = lower_bound(digit_cum_sum.begin(), digit_cum_sum.end(), n) - digit_cum_sum.begin();
    long long num = no[group_no - 1];
    num += (n - digit_cum_sum[group_no - 1]) / group_no;
    long long extra = (n - digit_cum_sum[group_no - 1]) % group_no;
    if (extra)
        cout << to_string(++num)[extra - 1] << "\n";
    else
        cout << num % 10 << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    digit_cum_sum.push_back(0);
    no.push_back(0);
    unsigned long long mul = 9;
    for (int i = 1; i <= 18; i++)
    {
        no.push_back(mul + no.back());
        digit_cum_sum.push_back(mul * i + digit_cum_sum.back());
        mul *= 10;
    }
    // cout << digit_cum_sum.size() << "\n";
    // for (auto i : digit_cum_sum)
    //     cout << i << "\n";
    // cout << "\n";
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}