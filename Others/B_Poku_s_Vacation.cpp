#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n;
    cin>>n;
    ll p = 1;
    while(1){
        ll k = (p*(p+1))/2;
        if(k>n){
            p--;break;
        }
        else{
            p++;
        }
    }
    cout<<p<<endl;
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