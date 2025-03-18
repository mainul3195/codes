#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

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
int a[100005];
int n, q;
vector<vector<int>> base = {
                        {1, 1},
                        {1, 0}},
                    Zero = {{0, 0}, {0, 0}}, iden = {{1, 0}, {0, 1}};
struct nd
{
    Mat a, lazy_m = Mat(iden);
    bool lazy = 0;
} seg[400005];
void build(int node = 1, int start = 1, int end = n)
{
    if (start == end)
    {
        seg[node].a = Mat(base).pow(a[start]);
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    seg[node].a = seg[2 * node].a + seg[2 * node + 1].a;
    return;
}
void pushDown(int node, int start, int end)
{
    seg[node].a *= seg[node].lazy_m;
    if (start != end)
    {
        seg[2 * node].lazy |= seg[node].lazy;
        seg[2 * node + 1].lazy |= seg[node].lazy;
        seg[2 * node].lazy_m *= seg[node].lazy_m;
        seg[2 * node + 1].lazy_m *= seg[node].lazy_m;
    }
    seg[node].lazy = 0;
    seg[node].lazy_m = Mat(iden);
    return;
}
void update(int l, int r, Mat ml, int node = 1, int start = 1, int end = n)
{
    if (seg[node].lazy)
        pushDown(node, start, end);
    if (start > r || end < l)
        return;
    if (start >= l && end <= r)
    {
        seg[node].lazy = 1;
        seg[node].lazy_m = ml;
        pushDown(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(l, r, ml, 2 * node, start, mid);
    update(l, r, ml, 2 * node + 1, mid + 1, end);
    seg[node].a = seg[2 * node].a + seg[2 * node + 1].a;
    return;
}
int query(int l, int r, int node = 1, int start = 1, int end = n)
{
    if (seg[node].lazy)
        pushDown(node, start, end);
    if (start > r || end < l)
        return 0;
    if (start >= l && end <= r)
        return seg[node].a.a[1][0];
    int mid = (start + end) / 2;
    return (query(l, r, 2 * node, start, mid) + query(l, r, 2 * node + 1, mid + 1, end)) % mod;
}
void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build();
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            update(l, r, Mat(base).pow(x));
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << "\n";
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