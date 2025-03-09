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

void solve()
{
    long long t, k, n;
    cin >> t >> k >> n;
    if (t == 0)
    {
        cout << "0\n";
        return;
    }
    // cout << "\n";
    vector<vector<int>> v(t + 1, vector<int>(t + 1, 0));
    v[0][0] = k + 1;
    v[0][t] = -k;
    for (int i = 1; i <= t; i++)
        v[i][i - 1] = 1;
    vector<vector<int>> b(t + 1, vector<int>(1, 1));
    for (int i = t - 1; i >= 0; i--)
        b[i][0] = b[i + 1][0] * (k + 1) % mod;
    b[0][0] = (b[0][0] - 1 + mod) % mod;
    // for (auto x : v)
    // {
    //     for (auto y : x)
    //         cout << y << " ";
    //     cout << "\n";
    // }
    // for (auto x : b)
    // {
    //     for (auto y : x)
    //         cout << y << " ";
    //     cout << "\n";
    // }
    if (n <= t)
    {
        cout << b[t - n][0] << "\n";
        return;
    }
    cout << ((Mat(v).pow(n - t) * Mat(b)).a[0][0] + mod) % mod << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}