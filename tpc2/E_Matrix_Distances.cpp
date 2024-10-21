
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1003;
int ara[N][N];
vector<pair<int, int>> pos[1000006];
void solve()
{
    int n, m;
    cin >> n >> m;
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ara[i][j];
            st.insert(ara[i][j]);
        }
    }
    unordered_map<int, int> mp;
    int j = 1;
    for (auto it : st)
    {
        mp[it] = j++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ara[i][j] = mp[ara[i][j]];
            // cout << mp[ara[i][j]] << " mp" << endl ;
            pos[ara[i][j]].push_back({i, j});
        }
    }
    int ans = 0;
    for (int ii = 1; ii < j; ii++)
    {

        vector<int> vx;
        vector<int> vy;
        vx.push_back(0);
        vy.push_back(0);
        for (auto [a, b] : pos[ii])
        {
            vx.push_back(a);
            vy.push_back(b);
        }
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());

        int sz = vx.size();
        vector<int> qsum_x(sz + 3, 0);
        vector<int> qsum_y(sz + 3, 0);
        long long tmp = 0;
        for (int i = 1; i < sz; i++)
        {
            qsum_x[i] += qsum_x[i - 1] + vx[i];
            qsum_y[i] += qsum_y[i - 1] + vy[i];
        }
        for (int i = 1; i < sz; i++)
        {
            long long tp1 = (qsum_x[sz - 1] - qsum_x[i]) - (vx[i] * 1ll * (sz - i - 1));
            long long tp2 = (vx[i] * 1ll * (i - 1)) - (qsum_x[i - 1]);
            tmp += (tp1 + tp2);

            long long tp3 = (qsum_y[sz - 1] - qsum_y[i]) - (vy[i] * 1ll * (sz - i - 1));

            long long tp4 = (vy[i] * 1ll * (i - 1)) - (qsum_y[i - 1]);
            tmp += (tp3 + tp4);
        }
        ans += tmp;
    }
    cout << ans << endl;
}

int32_t main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 1;
    while (tc--)
    {
        solve();
    }

    return 0;
}
