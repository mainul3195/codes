#include<bits/stdc++.h>
using namespace std;
#define Mod 998244353
long long bigMod(long long b, long long p)
{
    if(!p) return 1;
    if(p&1) return (b*bigMod(b, p-1))%Mod;
    long long T = bigMod(b, p/2);
    return (T*T)%Mod;
}
long long modInverse(long long n)
{
    return bigMod(n, Mod-2);
}
long long arr[100000];
void solve()
{
    int n, x;
    cin >> n >> x;
    arr[0] = 1;
    vector<int>v(n);
    for(auto &i: v)
        cin >> i;
    for(int i = 0; i<n; i++)
        for(int j = v[i]; j<=x; j++)
            (arr[j]+=arr[j-v[i]])%=Mod;
    long long in_favour;
    int mn = 100000;
    for(auto i: v)
        mn = min(mn, i);
    long long mn_count = 0;
    for(auto i: v)
        if(i==mn)
            mn_count++;
    long long len = (x+mn)/mn;
    long long full_len = bigMod(mn_count, len-1);
    in_favour = (full_len + (arr[x]-full_len)*n%Mod)%Mod;
    for(int i = x-1; i+v[0]>x; i--)
        (in_favour += arr[i]*n%Mod)%=Mod;
    cout << in_favour << " " << mn << " " << bigMod(n, len) << "\n";
    cout << in_favour*modInverse(bigMod(n , len))%Mod << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}