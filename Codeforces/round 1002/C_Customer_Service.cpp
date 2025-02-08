#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[j][n - i - 1];

    vector<vector<int>> v(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= n; i++)
        v[i][0] = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
            if (sum >= n)
                break;
            v[i][sum] = sum;
        }
    }
    for (auto &vec : v)
    {
        while (vec.back() == -1)
            vec.pop_back();
        int last;
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            if (vec[i] != -1)
                last = vec[i];
            else
                vec[i] = last;
        }
    }
    int last = n;
    int tar = n - 1;
    while (tar >= 0)
    {
        sort(v.begin(), v.end());
        auto l = v.back();
        if (l.back() != tar)
        {
            tar = l.back();
            last = tar + 1;
        }
        v.pop_back();
        for (auto &vec : v)
            while (vec.size() && vec.back() >= tar)
                vec.pop_back();
        tar--;
    }
    cout << last << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}