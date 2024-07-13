#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define ll long long int
#define pii pair<int, int>
#define sz 1000005
#define inf 2e9
#define mod 998244353
#define Mod 1000000007
#define pi acos(-1.0)

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first;
    for (int i = 0; i < n; i++)
        cin >> v[i].second;
    sort(v.begin(), v.end());
    int mnind[n], mn = v[0].first - v[0].second;
    mnind[0] = 0;
    for (int i = 1; i < n; i++)
    {
        mnind[i] = mnind[i - 1];
        if (v[i].first - v[i].second < mn)
        {
            mn = v[i].first - v[i].second;
            mnind[i] = i;
        }
    }

    ll myans = 0;

    ll preans[1000006];
    preans[0] = 0;

    for (int i = 1; i <= 1000000; i++)
    {
        ll x = i;
        int lo = 0, hi = n - 1;
        int ans = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (v[mid].first <= x)
            {
                ans = max(mid, ans);
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        if (ans != -1)
        {
            int ii = mnind[ans];
            int times = (x - v[ii].first) / (v[ii].first - v[ii].second);
            times++;
            x -= times * (v[ii].first - v[ii].second);
            preans[i] = times * 2 + preans[x];
        }
        else
        {
            preans[i] = 0;
        }
    }

    while (m--)
    {
        ll x;
        cin >> x;
        int lo = 0, hi = n - 1;
        int ans = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (v[mid].first <= x)
            {
                ans = max(mid, ans);
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        if (ans != -1)
        {
            int i = mnind[ans];
            int times = (x - v[i].first) / (v[i].first - v[i].second);
            times++;
            x -= times * (v[i].first - v[i].second);
            myans += times * 2 + preans[x];
        }
    }

    cout << myans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, tt = 0;

    // cin>>t;
    while (t--)
    {
        tt++;
        // cout<<"Case "<<tt<<": ";
        solve();
    }
    return 0;
}