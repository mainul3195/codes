#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long w, f;
    cin >> w >> f;
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    sort(v.rbegin(), v.rend());
    long long l = 1, r = 100000000, mid, ans;
    while(l<=r)
    {
        mid = (l+r)/2;
        long long totw = w*mid;
        long long totf = f*mid;
        bool ok = 1;
        for(auto s: v)
        {
            if(totw>=s)
            {
                totw-=s;
                continue;
            }
            if(totf>=s)
            {
                totf-=s;
                continue;
            }
            ok = 0;
            break;
        }
        if(ok)
        {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << "\n";
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