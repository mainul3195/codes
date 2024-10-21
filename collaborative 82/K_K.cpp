#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> sparseTable;
vector<int> lg(1000001, 0);
int n;
#define N 200005
int Table[N][22], a[N];

void Build()
{

    for (int i = 1; i <= n; i++)
        Table[i][0] = a[i];

    for (int k = 1; k < 22; k++)
    {
        for (int i = 1; i + (1 << k) - 1 <= n; i++)
            Table[i][k] = max(Table[i][k - 1], Table[i + (1 << (k - 1))][k - 1]);
    }
}

int Query(int l, int r)
{
    int k = lg[(r - l + 1)];
    return max(Table[l][k], Table[r - (1 << k) + 1][k]);
}

vector<vector<int>> pos;
long long calc(int l, int r)
{
    // cout << l << " " << r << "\n";
    if (l >= r)
        return 0;
    int x = Query(l, r);
    // cout << x << "\n";
    long long ans = 0;
    int p = lower_bound(pos[x].begin(), pos[x].end(), l) - pos[x].begin();
    int prev = l;
    int i;
    for (i = p; i < pos[x].size(); i++)
    {
        if (pos[x][i] > r)
            break;
        ans += calc(prev, pos[x][i] - 1) + max(0, pos[x][i] - prev);
        prev = pos[x][i] + 1;
    }
    // cout << "l " << l << " r " << r << " ans " << ans << "prev " << prev <<  "\n";
    ans += calc(prev, r) + max(0, r - prev + 1);
    return ans;
}
void solve()
{
    cin >> n;
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
    }
    map<int, int> mp;
    int val = 0;
    for (auto i : st)
        mp[i] = ++val;
    for (int i = 1; i <= n; i++)
        a[i] = mp[a[i]];
    pos = vector<vector<int>>(val + 2);
    for (int i = 1; i <= n; i++)
        pos[a[i]].push_back(i);
    Build();
    // cout << "ok\n";
    cout << calc(1, n) << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i <= 1000000; i++)
        lg[i] = lg[i / 2] + 1;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}