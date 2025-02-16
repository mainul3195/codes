#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
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
    inline void make_unit()
    {
        assert(n == m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                a[i][j] = i == j;
        }
    }
    inline Mat operator+(const Mat &b)
    {
        assert(n == b.n && m == b.m);
        Mat ans = Mat(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans.a[i][j] = (a[i][j] + b.a[i][j]);
            }
        }
        return ans;
    }
    inline Mat operator-(const Mat &b)
    {
        assert(n == b.n && m == b.m);
        Mat ans = Mat(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans.a[i][j] = (a[i][j] - b.a[i][j]);
            }
        }
        return ans;
    }
    inline Mat operator*(const Mat &b)
    {
        assert(m == b.n);
        Mat ans = Mat(n, b.m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < b.m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j]);
                }
            }
        }
        return ans;
    }
    inline Mat pow(long long k)
    {
        assert(n == m);
        Mat ans(n, n), t = a;
        ans.make_unit();
        while (k)
        {
            if (k & 1)
                ans = ans * t;
            t = t * t;
            k >>= 1;
        }
        return ans;
    }
};

void solve()
{
    int p, q, n;
    cin >> p >> q >> n;
    // cout << p << " " << q << " " << n << "\n";
    vector<vector<int>> v = {
        {p, -q},
        {1, 0}};
    vector<vector<int>> mt = {
        {p},
        {2}};
    if (n == 0)
    {
        cout << 2 << "\n";
        return;
    }
    Mat a(v);
    // for (int i = 0; i < 2; i++)
    //     for (int j = 0; j < 2; j++)
    //         cout << a.a[i][j] << " \n"[j == 2 - 1];
    cout << (Mat(v).pow(n - 1) * Mat(mt)).a[0][0] << "\n";

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    // int a = 0;
    // int b = 1;
    // for (int i = 1; i <= 50; i++)
    // {
    //     int c = (a + b) % 100000;
    //     a = b;
    //     b = c;
    //     cout << i << " " << c << "\n";
    // }
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}