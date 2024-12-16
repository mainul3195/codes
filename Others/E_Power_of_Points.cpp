#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, int>&p1, pair<long long, int>&p2)
{
    return p1.second<p2.second;
}
void solve()
{
    int n;
    cin >> n;
    vector<long long> right_sum(n, 0), left_sum(n, 0);
    vector<pair<long long, int>> v;
    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    for(int i = n-2; i>=0; i--)
        right_sum[i] = right_sum[i+1]+v[i+1].first;
    for(int i = 1; i<n; i++)
        left_sum[i] = left_sum[i-1]+v[i-1].first;
    vector<long long> ans(n);
    for(int i = 0; i<n; i++)
        ans[i]= 1+right_sum[i]-(v[i].first-1)*(n-i-1) + v[i].first*(i)-left_sum[i]+(i);
    for(int i = 0; i<n; i++)
        v[i].first = ans[i];
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i<n; i++)
        cout << v[i].first << " ";
        cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}