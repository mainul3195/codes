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
    long long n;
    cin >> n;
    if (n == 0)
        cout << 0 << "\n";
    else if (n == 1)
        cout << 2 << "\n";
    else
    {
        vector<vector<int>> tmp = {
            {1, 1},
            {1, 0}};
        cout << Mat(tmp).pow(n + 2).a[0][0] << "\n";
    }

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