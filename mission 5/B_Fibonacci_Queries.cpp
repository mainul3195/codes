#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

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
                ans.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
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
                ans.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
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
                    ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % mod) % mod;
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
    inline Mat &operator+=(const Mat &b) { return *this = (*this) + b; }
    inline Mat &operator-=(const Mat &b) { return *this = (*this) - b; }
    inline Mat &operator*=(const Mat &b) { return *this = (*this) * b; }
    inline bool operator==(const Mat &b) { return a == b.a; }
    inline bool operator!=(const Mat &b) { return a != b.a; }
};
vector<int> v;
vector<Mat> seg;
int n, m;
Mat base;
void build(int node = 1, int s = 1, int e = n)
{
    if (s == e)
    {
        seg[node] = base.pow(0) + base.pow(v[s]);
        return;
    }
    int mid = (s + e) / 2;
    build(2 * node, s, mid);
    build(2 * node + 1, mid + 1, e);
    seg[node] = seg[2 * node] * seg[2 * node + 1];
    return;
}
Mat query(int l, int r, int node = 1, int s = 1, int e = n)
{
    if (s > r || e < l)
        return base.pow(0);
    if (s >= l && e <= r)
        return seg[node];
    int mid = (s + e) / 2;
    return query(l, r, 2 * node, s, mid) * query(l, r, 2 * node + 1, mid + 1, e);
}
void update(int ind, int val, int node = 1, int s = 1, int e = n)
{
    if (s == e)
    {
        seg[node] = base.pow(0) + base.pow(val);
        return;
    }
    int mid = (s + e) / 2;
    ind <= mid ? update(ind, val, 2 * node, s, mid) : update(ind, val, 2 * node + 1, mid + 1, e);
    seg[node] = seg[2 * node] * seg[2 * node + 1];
    return;
}
void solve()
{
    cin >> n >> m;
    seg = vector<Mat>(4 * n, Mat(2, 2));
    v = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<vector<int>> tmp = {
        {1, 1},
        {1, 0}};
    base = Mat(tmp);
    build();
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "\n i = " << i << "\n";
    //     Mat x = query(i, i);
    //     for (int j = 0; j < 2; j++)
    //     {
    //         for (int k = 0; k < 2; k++)
    //             cout << x.a[j][k] << " ";
    //         cout << "\n";
    //     }
    // }
    while (m--)
    {
        char c;
        cin >> c;
        if (c == 'C')
        {
            int x, y;
            cin >> x >> y;
            update(x, y);
            // for (int i = 1; i <= n; i++)
            // {
            //     cout << "\n i = " << i << "\n";
            //     Mat x = query(i, i);
            //     for (int j = 0; j < 2; j++)
            //     {
            //         for (int k = 0; k < 2; k++)
            //             cout << x.a[j][k] << " ";
            //         cout << "\n";
            //     }
            // }
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(l, r).a[0][1] << "\n";
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}