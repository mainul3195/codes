#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    vector<int> pos;
    long long sum = 0;
    long long mn = 10000000;
    for (auto i : v)
        mn = min(mn, i);
    for (int i = 0; i < k; i++)
    {
        sum += v[i];
        if (v[i] > mn)
            pos.push_back(i);
    }
    int i = k - 1;
    long long tot = 0;
    while (1)
    {
        // cout << i << " -> " << sum << "\n";
        // for (auto j : pos)
        //     cout << j << " ";
        // cout << "\n";
        int st = i - k + 1;
        while (sum >= 0)
        {
            int last_ind = pos.back();
            pos.pop_back();
            int can_reduce = v[last_ind] - mn;
            int to_reduce = sum + 1;
            if (to_reduce >= can_reduce)
                sum -= can_reduce, v[last_ind] = mn, tot += can_reduce;
            else
            {
                sum -= to_reduce;
                v[last_ind] -= to_reduce;
                tot += to_reduce;
                pos.push_back(last_ind);
            }
        }
        i++;
        if (i == n)
            break;
        sum += v[i];
        if (v[i] > mn)
            pos.push_back(i);
        sum -= v[i - k];
    }
    cout << tot << "\n";
    for (int i = 0; i < n; i++)
        cout << v[i] << " \n"[i == n - 1];
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}