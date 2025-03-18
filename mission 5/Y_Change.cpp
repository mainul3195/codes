#include <bits/stdc++.h>
using namespace std;

struct Mat
{
    int n, m;
    vector<vector<__int128_t>> a;
    Mat() {}
    Mat(int _n, int _m)
    {
        n = _n;
        m = _m;
        a.assign(n, vector<__int128_t>(m, 0));
    }
    Mat(vector<vector<__int128_t>> v)
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
    inline Mat &operator+=(const Mat &b) { return *this = (*this) + b; }
    inline Mat &operator-=(const Mat &b) { return *this = (*this) - b; }
    inline Mat &operator*=(const Mat &b) { return *this = (*this) * b; }
    inline bool operator==(const Mat &b) { return a == b.a; }
    inline bool operator!=(const Mat &b) { return a != b.a; }
};
void print(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
void solve()
{
    vector<int> dp(501, 0);
    dp[0] = 1;
    vector<int> tmp = {1, 5, 10, 25, 50};
    for (auto el : tmp)
        for (int i = el; i <= 500; i++)
            dp[i] += dp[i - el];
    for (int i = 0; i <= 500; i++)
        cout << i << " -> " << dp[i] << "\n";
    vector<vector<__int128_t>> base(50, vector<__int128_t>(1));
    for (int i = 0; i < 50; i++)
        base[i][0] = dp[50 - i];
    vector<vector<__int128_t>> v(50, vector<__int128_t>(50, 0));
    v[0][0] = v[0][4] = v[0][9] = v[0][24] = v[0][49] = 1;
    for (int i = 1; i < 50; i++)
        v[i][i - 1] = 1;
    int n;
    while (cin >> n)
    {
        n--;
        if (n < 50)
        {
            print(base[50 - n - 1][0]);
            cout << "\n";
            continue;
        }
        print(((Mat(v).pow(n - 49))*Mat(base)).a[0][0]);
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}