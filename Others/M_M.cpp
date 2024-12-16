#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
long long bit[200000];
vector<pair<int, int>>v;
void upd(int ind, long long val)
{
    for(; ind<=n; ind += (ind&(-ind)))
        bit[ind]+=val;
}
long long query(int ind)
{
    long long ans = 0;
    for(; ind; ind-=(ind&(-ind)))
        ans += bit[ind];
    return ans;
}
long long sm(int l, int r)
{
    return query(r)-query(l-1);
}
void solve()
{
    cin >> n >> k;
    memset(bit, 0, sizeof(long long)*(n+5));
    v = vector<pair<int, int>>(n+1);
    v[0] = {-1, -1};
    for(int i = 1; i<=n; i++)
        cin >> v[i].first;
    for(int i = 1; i<=n; i++)
        cin >> v[i].second;
    sort(v.begin(), v.end());
    for(int i = 1; i<=n; i++ )
        upd(i, v[i].second);
    int l = 1, r = n;
    
    for(int i = 1; i<=k; i++)
    {
        long long m;
        cin >> m;
        if(i&1)
        {
            int tl = l, tr = r, mid, ans = r+1;
            while(tl<=tr)
            {
                mid = (tl+tr)/2;
                if(sm(mid, r)<=m)
                {
                    ans = mid;
                    tr = mid-1;
                }
                else
                    tl = mid+1;
            }
            if(ans == r+1)
            {
                l = r = r;
                upd(l, m-sm(l, l));
            }
            else 
            {
                long long diff = m-sm(ans, r);
                if(diff && ans>l)
                {
                    ans--;
                    upd(ans, diff-sm(ans, ans));
                }
                l = ans;
            }
        }
        else
        {
            int tl = l, tr = r, mid, ans = l-1;
            while(tl<=tr)
            {
                mid = (tl+tr)/2;
                if(sm(l, mid)<=m)
                {
                    ans = mid;
                    tl = mid+1;
                }
                else tr = mid-1;
            }
            if(ans == l-1)
            {
                l = r = l;
                upd(l, m-sm(l, l));
            }
            else
            {
                long long diff = m-sm(l, ans);
                if(diff && ans<r)
                {
                    ans++;
                    upd(ans, diff-sm(ans, ans));
                }
                r = ans;
            }
        }
        // cout << l << " " << r << "\n";
    }
    long long sum = 0;
    for(int i = l; i<=r; i++)
        sum += sm(i, i)*v[i].first;
    cout << sum << "\n";

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