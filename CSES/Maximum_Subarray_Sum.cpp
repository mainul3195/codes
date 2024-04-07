#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    long long cur_sum = 0, mx_sum = 0;
    for (auto i : v)
    {
        cur_sum += i;
        if (cur_sum < 0)
            cur_sum = 0;
        mx_sum = max(mx_sum, cur_sum);
    }
    if (mx_sum == 0)
    {
        mx_sum = -2000000000;
        for (auto i : v)
            mx_sum = max(mx_sum, i);
    }
    cout << mx_sum << "\n";
    return 0;
}