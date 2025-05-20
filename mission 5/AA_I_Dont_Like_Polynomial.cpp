#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define Mat array<array<int, 8>, 8>
Mat operator*(const Mat &a, const Mat &b)
{
    Mat c = {};
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            int sum = 0;
            for (int k = 0; k < 8; k++)
                sum = (sum + 1LL * a[i][k] * b[k][j] % mod) % mod;
            c[i][j] = sum;
        }
    return c;
}
Mat iden = {{{1, 0, 0, 0, 0, 0, 0, 0},
             {0, 1, 0, 0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0, 0, 0, 0},
             {0, 0, 0, 1, 0, 0, 0, 0},
             {0, 0, 0, 0, 1, 0, 0, 0},
             {0, 0, 0, 0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0, 0, 1, 0},
             {0, 0, 0, 0, 0, 0, 0, 1}}};
Mat Pow(const Mat &b, int p)
{
    if (!p)
        return iden;
    if (p & 1)
        return b * Pow(b, p - 1);
    Mat t = Pow(b, p / 2);
    return t * t;
};

Mat v, pre[64];
array<array<int, 1>, 8> base;
array<array<int, 1>, 8> mul(const array<array<int, 8>, 8> &a, array<array<int, 1>, 8> &b)
{
    array<array<int, 1>, 8> c = {};
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 1; j++)
        {
            int sum = 0;
            for (int k = 0; k < 8; k++)
                sum = (sum + 1LL * a[i][k] * b[k][j] % mod) % mod;
            c[i][j] = sum;
        }
    return c;
}
void solve()
{
    // for (int m = 0; m < 1000; m++)
    // {
    long long m;
    cin >> m;
    if (m < 8)
        cout << base[7 - m][0] << '\n';
    else
    {
        long long p = m - 7;
        int ind = 0;
        array<array<int, 1>, 8> ans = base;
        while (p)
        {
            if (p & 1)
                ans = mul(pre[ind], ans);
            ind++;
            p >>= 1;
        }
        cout << ans[0][0] << "\n";
    }
    // }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    base[7][0] = {1};
    base[6][0] = {2};
    base[5][0] = {4};
    base[4][0] = {6};
    base[3][0] = {10};
    base[2][0] = {14};
    base[1][0] = {20};
    base[0][0] = {26};
    v[0][0] = 2;
    v[0][1] = 0;
    v[0][2] = -2 + mod;
    v[0][3] = 2;
    v[0][4] = -2 + mod;
    v[0][5] = 0;
    v[0][6] = 2;
    v[0][7] = -1 + mod;
    for (int i = 1; i < 8; i++)
        v[i][i - 1] = 1;
    pre[0] = v;
    for (int i = 1; i < 64; i++)
        pre[i] = pre[i - 1] * pre[i - 1];
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}