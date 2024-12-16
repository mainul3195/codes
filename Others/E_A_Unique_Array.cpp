#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define clean(x, y) memset(x, y, sizeof(x));
#define endl "\n"
#define MOD 1000000007
#define MAX 200005

typedef long long ll;

int bit[MAX], n;
vector<int> v;
int query(int x)
{
    ll ans = 0;
    for (; x > 0; x -= (x & (-x)))
        ans += bit[x];
    return ans;
}
void update(int x, int val)
{
    for (; x <= n; x += (x & (-x)))
        bit[x] += val;
}
int get_idx(int x)
{
    x++;
    int l = 1, r = n, m, idx = -1;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (query(m) >= x)
        {
            idx = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return idx - 1;
}
void solve()
{
    memset(bit, 0, sizeof bit);
    int q;
    cin >> n >> q;
    v.clear();
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        update(i, 1);
    }
    int ans = n;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int l = -1, r = -1, m = -1;
        if (x > 0)
            l = get_idx(x - 1);
        m = get_idx(x);
        if (x + 1 < ans)
            r = get_idx(x + 1);
        if (l != -1 && v[l] == y)
        {
            ans--;
            update(l+1, -1);
        }
        if (r != -1 && v[r] == y)
        {
            ans--;
            update(r+1, -1);
        }
        v[m] = y;
        cout << ans << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC = 1;

    cin >> TC;
    cin.ignore();

    for (int cs = 1; cs <= TC; cs++)
    {
        cout << "Case " << cs << ":\n";
        solve();
    }

    return 0;
}