#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    long long l = 1, r = 1500000000LL, mid, ans;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(mid*(mid-1)/2<=n)
        {
            ans = mid;
            l = mid+1;
        }
        else r=mid-1;
    }
    cout << ans+n-ans*(ans-1)/2 << "\n";
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