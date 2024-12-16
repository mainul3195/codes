#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n,k;
    cin>>n>>k;
    ll ct = 1, r = n-1;
    ll t = 0;
    while(1){
        if(r<=0) break;
        ll mn = min(ct,k);
        r-=mn;
        t++;
        ct+=mn;

    }
    cout<<t<<endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve(); 
    return 0;
}