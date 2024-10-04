#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mx 500005
long long cnt[mx];
vector<int> factors[mx];
void sieve()
{
    for (int i = 2; i < mx; i += 2)
        factors[i].push_back(2);
    for (int i = 3; i * i < mx; i += 2)
        if (factors[i].empty())
        {
            for (int j = i; j < mx; j += i)
                factors[j].push_back(i);
        }
}
int n, q;
void solve()
{
    cin >> n >> q;
    long long ans = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    map<int, bool> mp;
    long long tot_num = 0;
    while (q--)
    {
        // for (int i = 1; i <= 6; i++)
        //     cout << i << " -> " << cnt[i] << "\n";
        int x;
        cin >> x;
        x = a[x];
        if (!mp[x])
        {
            long long tot = 0;
            mp[x] = 1;
            if (x == 1)
            {
                ans += tot_num;
                cnt[1]++;
                tot_num++;
                cout << ans << "\n";
                continue;
            }
            int lim = 1 << factors[x].size();
            for (int i = 1; i < lim; i++)
            {
                long long mul = 1;
                for (int j = 0; (1 << j) <= i; j++)
                    if (i & (1 << j))
                        mul *= factors[x][j];
                if (__builtin_popcount(i) % 2)
                    tot += cnt[mul];
                else
                    tot -= cnt[mul];
                cnt[mul]++;
            }
            ans += (tot_num - tot);
            tot_num++;
        }
        else
        {
            long long tot = 0;
            mp[x] = 0;
            if (x == 1)
            {
                tot_num--;
                ans -= tot_num;
                cnt[1]--;
                cout << ans << "\n";
                continue;
            }
            int lim = 1 << factors[x].size();
            for (int i = 1; i < lim; i++)
            {
                long long mul = 1;
                for (int j = 0; (1 << j) <= i; j++)
                    if (i & (1 << j))
                        mul *= factors[x][j];
                if (__builtin_popcount(i) % 2)
                    tot += cnt[mul];
                else
                    tot -= cnt[mul];
                cnt[mul]--;
            }
            // if (!q)
            //     cout << tot << " " << tot_num << "\n";
            ans -= (tot_num - tot);
            tot_num--;
        }
        cout << ans << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    solve();
    return 0;
}