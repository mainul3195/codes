#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    int tor = 0;
    for(int i: v)
        tor |= i;
    // cout << "tor = " << tor << "\n";
    int l = 1, r = n, mid, ans;
    while(l<=r)
    {
        mid = (l+r)/2;
        bool ok = 1;
        int Or = 0, cnt[21] = {0};
        for(int i = 0; i<mid; i++)
        {
            Or |= v[i];
            int tmp = v[i];
            int ind = 0;
            while(tmp)
            {
                if(tmp%2)
                    cnt[ind]++;
                tmp>>=1;
                ind++;
            }
        }
        // cout << "Or = " << Or << "\n";
        if(Or != tor)
            ok = 0;
        else
        {
            for(int i = 1; i+mid-1<n; i++)
            {
                int tmp = v[i-1];
                int ind = 0;
                while(tmp)
                {
                    if(tmp%2)
                    {
                        cnt[ind]--;
                        if(cnt[ind]==0)
                            Or ^= (1<<ind);
                    }
                    tmp>>=1;
                    ind++;
                }
                tmp = v[i+mid-1];
                ind = 0;
                Or |= tmp;
                while(tmp)
                {
                    if(tmp%2)
                        cnt[ind]++;
                    tmp>>=1;
                    ind++;
                }
                if(Or != tor)
                {
                    ok = 0;
                    break;
                }
            }
        }
        if(ok)
        {
            ans = mid;
            r = mid-1;
        }
        else 
            l = mid+1;
        // cout << l << " " << r << " " << ok << "\n";
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