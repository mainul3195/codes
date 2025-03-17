#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000000;

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
int len, k;
vector<vector<int>> base, v;
long long SUM(long long x)
{
    if (x <= k)
    {
        long long sum = 0;
        for (int i = k, cnt = x; cnt--; i--)
            (sum += base[i][0]) %= mod;
        return sum;
    }
    return ((Mat(v).pow(x - k)) * Mat(base)).a[0][0];
}
void solve()
{
    cin >> k;
    base = vector<vector<int>>(k + 1, vector<int>(1));
    for (int i = 0; i < k; i++)
        cin >> base[k - i][0];
    long long sum = 0;
    for (int i = 1; i <= k; i++)
        sum += base[i][0];
    base[0][0] = sum;
    // cout << "\n";
    // for (auto a : base)
    // {
    //     for (auto b : a)
    //         cout << b << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    v = vector<vector<int>>(k + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= k; i++)
    {
        cin >> v[0][i];
        v[1][i] = v[0][i];
    }
    v[0][0] = 1;
    for (int i = 2; i <= k; i++)
        v[i][i - 1] = 1;

    // for (auto a : v)
    // {
    //     for (auto b : a)
    //         cout << b << " ";
    //     cout << "\n";
    // }

    // for (int i = 1; i <= 12; i++)
    // {
    //     cout << i << " -> \n";
    //     Mat mm = ((Mat(v).pow(i)) * Mat(base));
    //     cout << "\n";
    //     for (auto a : mm.a)
    //     {
    //         for (auto b : a)
    //             cout << b << " ";
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }
    long long l, r;
    cin >> l >> r >> mod;
    cout << (SUM(r) - SUM(l - 1) + mod) % mod << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << ++tc << ": ";
        solve();
    }
    return 0;
}