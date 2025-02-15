#include <bits/stdc++.h>
using namespace std;

long long mod;

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

// int32_t main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   int n; long long k; cin >> n >> k;
//   Mat a(n, n);
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//       cin >> a.a[i][j];
//     }
//   }
//   Mat ans = a.pow(k);
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//       cout << ans.a[i][j] << ' ';
//     }
//     cout << '\n';
//   }
//   return 0;
// }
// // https://judge.yosupo.jp/problem/pow_of_matrix
void solve()
{
    long long a, b, n, m;
    cin >> a >> b >> n >> m >> mod;
    vector<vector<int>> v(2, vector<int>(2));
    v[0][0] = a;
    v[0][1] = b;
    v[1][0] = 0;
    v[1][1] = 1;
    vector<vector<int>> mt(2, vector<int>(1));
    mt[0][0] = m * (m + 1) / 2 % mod;
    mt[1][0] = m % mod;

    cout << (Mat(v).pow(n) * Mat(mt)).a[0][0] << "\n";

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