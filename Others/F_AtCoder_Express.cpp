#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), mx(n);
    int sum = 0;
    for (auto &i : v)
    {
        cin >> i;
        i <<= 1;
        sum += i;
    }
    for (auto &i : mx)
    {
        cin >> i;
        i <<= 1;
    }

    vector<long long> height(sum + 5, 1000000);
    vector<pair<int, int>> joints;
    int start = 0, prev = 100000000;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            joints.push_back({0, 0});
        else
            joints.push_back({start, min(prev, mx[i])});
        prev = mx[i];
        int lim = start + v[i];
        for (int j = start; j <= lim; j++)
            height[j] = min((int)height[j], mx[i]);
        start += v[i];
    }
    joints.push_back({sum, 0});
    // for (auto [a, b] : joints)
    //     cout << a << " " << b << "\n";

    for (auto [x, h] : joints)
    {
        int tmp = h;
        for (int i = x; i <= sum; i++)
        {
            height[i] = min((int)height[i], tmp);
            tmp++;
        }
        tmp = h;
        for (int i = x; i >= 0; i--)
        {
            height[i] = min((int)height[i], tmp);
            tmp++;
        }
    }
    // for (int i = 0; i < height.size(); i++)
    // {
    //     cout << i << " -> " << height[i] << "\n";
    // }

    double ans = 0;
    for (int i = 1; i <= sum; i++)
        ans += min(height[i], height[i - 1]) + (height[i] == height[i - 1] ? 0.0 : 0.5);
    cout << fixed << setprecision(5) << ans / 4 << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}