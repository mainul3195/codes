#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &i: v)
        cin >> i; 
    long long ans = 0;
    for(int k = 0; k<=30; k++)
    {
        long long len_sum[2] = {0}, cum_xor = 0, minus[2] = {0}, prev[2] = {0}, add[2] = {0};
        int src;
        for(int i = 0; i<n; i++)
        {
            len_sum[0] = (len_sum[0]+add[0])%mod;
            len_sum[1] = (len_sum[1]+add[1])%mod;
            int cur = v[i]&(1<<k);
            cum_xor ^= cur;
            if(cur == cum_xor)
                src = !cur;
            else src = cur;
            long long tmp = (len_sum[src] - prev[src]+mod)%mod<<(k)%mod;
            ans = (ans+tmp)%mod;
            if(src)
                add[1]++;
            else add[0]++;
        }
    }
    cout << ans << "\n";
    return 0;
}