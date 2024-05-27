#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int mx = (n+m-1)/m;
    mx = n-mx;
    if(mx<=k)
        cout << "NO\n";
    else cout << "YES\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve(); 
    return 0;
}