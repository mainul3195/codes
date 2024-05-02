#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> HASH, REV_HASH, POW;
vector<int> BASE = {1231, 1567}, MOD = {1000000000 + 7, 1000000000 + 9};
int lim;
string text, pattern;
void init()
{
    POW = HASH = vector<vector<long long>>(2, vector<long long>(200005));
    POW[0][0] = POW[1][0] = 1;
    for (int b = 0; b < 2; b++)
        for (int j = 1; j < 200005; j++)
            POW[b][j] = (POW[b][j - 1] * BASE[b]) % MOD[b];
    return;
}
void initHash(string str)
{
    int len = str.size();
    HASH[0][0] = HASH[1][0] = 0;
    for (int b = 0; b < 2; b++)
        for (int i = 1; i <= len; i++)
            HASH[b][i] = (HASH[b][i - 1] * BASE[b] + (str[i - 1] - 'a' + 1)) % MOD[b];
    return;
}

long long getHash(int left, int right, int hsh)
{
    int len = (right - left + 1);
    long long ret = (HASH[hsh][right] - HASH[hsh][left - 1] * POW[hsh][len]) % MOD[hsh];
    if (ret < 0)
        ret += MOD[hsh];
    return ret;
}
pair<long long, long long> getHash(int left, int right)
{
    long long hsh0 = getHash(left, right, 0);
    long long hsh1 = getHash(left, right, 1);
    return {hsh0, hsh1};
}
int n, k;
string s;
bool ok(int m)
{
    // return 1;
    auto frst = getHash(1, m);
    int cnt = 1;
    for (int i = m + 1; i + m - 1 <= n;)
    {
        if (frst == getHash(i, i + m - 1))
        {
            cnt++;
            i = i + m;
        }
        else
            i++;
    }
    // cout << cnt << "\n";
    return cnt >= k;
}

void solve()
{
    cin >> n >> k >> k >> s;
    // cout << n << " " << k << "\n";
    lim = n + 2;
    initHash(s);
    int l = 1, r = n, mid, ans = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (ok(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    // cout << ok(3) << "\n";
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}