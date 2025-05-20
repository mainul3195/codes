#include <bits/stdc++.h>
using namespace std;
#define mxN 1000006
long long calculate(vector<long long> &v)
{
    vector<long long> vec;
    vec.push_back(v.back());
    v.pop_back();
    while (v.size())
    {
        if (vec.back() == v.back())
            vec[vec.size() - 1] += v.back();
        else
            vec.push_back(v.back());
        v.pop_back();
    }
    long long even_sum = 0, odd_sum = 0;
    for (int i = 0; i < vec.size(); i += 2)
        even_sum += vec[i];
    for (int i = 1; i < vec.size(); i += 2)
        odd_sum += vec[i];
    return max(even_sum, odd_sum);
}
long long ar[mxN + 1];
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    sort(ar, ar + n);
    vector<long long> v;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v.empty())
            v.push_back(ar[i]);
        else
        {
            if (ar[i] - v.back() > 1)
                ans += calculate(v);
            v.push_back(ar[i]);
        }
    }
    ans += calculate(v);
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}