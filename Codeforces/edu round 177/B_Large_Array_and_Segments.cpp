#include<bits/stdc++.h>
using namespace std;
long long n, k, x;
vector<long long>v;
bool possible(long long m)
{
    long long tot = v[n]*(m/n) + v[m%n];
    return tot >= x;
}
void solve()
{
    cin >> n >> k >> x;
    v = vector<long long> (n);
    for(auto &i: v)
        cin >> i;
    v.push_back(0);
    reverse(v.begin(), v.end());
    for(int i = 1; i<=n; i++)
        v[i] += v[i-1];
    // for(auto i: v)
        // cout << i << " ";
        // cout << "\n";
    long long ans = n*k+1;
    long long l = 1, r = n*k;
    while(l<=r)
    {
        long long mid = (l+r)/2;
        if(possible(mid))
        {
            ans = mid;
            r = mid-1;
        }
        else
        l = mid+1;
        }
    
    cout << n*k-ans+1 << "\n";
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