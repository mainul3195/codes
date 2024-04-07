#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> spt, start, nd;
vector<int> mx;
int n, k, lg[100005];
int Gcd(int l, int r)
{
    int len = r - l + 1;
    int k = lg[len];
    return __gcd(spt[l][k], spt[r - (1 << k) + 1][k]);
}
void solve()
{
    cin >> n;
    mx = vector<int>(n + 1);
    start = nd = vector<vector<int>>(n + 1);
    spt = vector<vector<int>>(n + 2, vector<int>(log2(n) + 2, -1));
    for (int i = 0; i < n; i++)
        cin >> spt[i][0];
    k = log2(n) + .5;
    for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) - 1 < n; i++)
            spt[i][j] = __gcd(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
    for (int i = 0; i < n; i++)
    {
        int strt = i;
        while (strt < n)
        {
            int g = Gcd(i, strt);
            int l = strt, r = n - 1, ans, mid;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (Gcd(i, mid) == g)
                {
                    ans = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            start[strt - i + 1].push_back(g);
            nd[ans - i + 1].push_back(g);
            strt = ans + 1;
        }
    }
    multiset<int> st;
    for (int i = 1; i <= n; i++)
    {
        for (auto v : start[i])
            st.insert(v);
        mx[i] = *st.rbegin();
        for (auto v : nd[i])
            st.erase(st.find(v));
    }
    for (int i = 1; i <= n; i++)
        cout << mx[i] << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lg[1] = 0;
    for (int i = 2; i < 100005; i++)
        lg[i] = lg[i / 2] + 1;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}