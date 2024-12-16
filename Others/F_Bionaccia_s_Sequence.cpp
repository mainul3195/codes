#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
struct Mat
{
    int n, m;
    vector<vector<int>> a;
    Mat() {}
    Mat(int _n, int _m)
    {
        n = _n;
        m = _m;
        a.assign(n, vector<int>(m, 0));
    }
    Mat(vector<vector<int>> v)
    {
        n = v.size();
        m = n ? v[0].size() : 0;
        a = v;
    }
    inline Mat operator*(const Mat &b)
    {
        Mat ans = Mat(n, b.m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < b.m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % mod) % mod;
                }
            }
        }
        return ans;
    }
    inline void make_unit()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = i == j;
    }
    inline Mat pow(long long k)
    {
        Mat ans(n, n), t = a;
        ans.make_unit();
        while (k)
        {
            if (k & 1)
            {
                ans = ans * t;
            }
            t = t * t;
            k >>= 1;
        }
        return ans;
    }
};
vector<vector<int>> co = {
                        {3, 2, 1, 3},
                        {1, 0, 0, 0},
                        {0, 1, 0, 0},
                        {0, 0, 0, 1}},
                    base = {{3, 0, 0, 0}, {2, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}};
void solve()
{
    int n;
    cin >> n;
    if (n < 3)
    {
        cout << n + 1 << "\n";
        return;
    }
    Mat c(co), b(base);
    Mat tmp = c.pow(n - 2);
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //         cout << tmp.a[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n\n";
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //         cout << b.a[i][j] << " ";
    //     cout << "\n";
    // }
    Mat ans = tmp * b;
    cout << ans.a[0][0] << "\n";
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //         cout << ans.a[i][j] << " ";
    //     cout << "\n";
    // }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}