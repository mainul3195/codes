#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define Mat array<array<int, 2>, 2>

Mat operator+(const Mat &a, const Mat &b)
{
    Mat c;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            c[i][j] = (a[i][j] + b[i][j]) % mod;
    return c;
}
Mat operator*(const Mat &a, const Mat &b)
{
    Mat c = {};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            int sum = 0;
            for (int k = 0; k < 2; k++)
                sum = (sum + 1LL * a[i][k] * b[k][j] % mod) % mod;
            c[i][j] = sum;
        }
    return c;
}
Mat iden = {{{1, 0}, {0, 1}}};
Mat Pow(const Mat &b, int p)
{
    if (!p)
        return iden;
    if (p & 1)
        return b * Pow(b, p - 1);
    Mat t = Pow(b, p / 2);
    return t * t;
};

int a[100005];
int n, q;
Mat base = {{{1, 1},
             {1, 0}}};
struct nd
{
    Mat a, lazy_m = iden;
    bool lazy = 0;
} seg[400005];
void build(int node = 1, int start = 1, int end = n)
{
    if (start == end)
    {
        seg[node].a = Pow(base, a[start]);
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
    seg[node].a = seg[node].a * seg[node].lazy_m;
    if (start != end)
    {
        seg[2 * node].lazy |= seg[node].lazy;
        seg[2 * node + 1].lazy |= seg[node].lazy;
        seg[2 * node].lazy_m = seg[2 * node].lazy_m * seg[node].lazy_m;
        seg[2 * node + 1].lazy_m = seg[2 * node + 1].lazy_m * seg[node].lazy_m;
    }
    seg[node].lazy = 0;
    seg[node].lazy_m = iden;
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
        return seg[node].a[1][0];
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
            update(l, r, Pow(base, x));
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