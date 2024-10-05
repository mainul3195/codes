#include <bits/stdc++.h>
using namespace std;
unsigned int b1 = 1021, b2 = 569;
vector<unsigned int> pow1, pow2;
string s;
int N;
void pre()
{
    pow1 = pow2 = vector<unsigned int>(N);
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < N; i++)
    {
        pow1[i] = (pow1[i - 1] * b1);
        pow2[i] = (pow2[i - 1] * b2);
    }
}
vector<pair<unsigned int, unsigned int>> H, rH;
void calc()
{
    int n = s.size();
    H = rH = vector<pair<unsigned int, unsigned int>>(N, {0, 0});
    for (int i = 1; i <= n; i++)
        H[i] = {
            (b1 * H[i - 1].first + s[i - 1] - '0' + 1),
            (b2 * H[i - 1].second + s[i - 1] - '0' + 1)};
    for (int i = n; i > 0; i--)
        rH[i] = {
            (b1 * rH[i + 1].first + s[i - 1] - '0' + 1),
            (b2 * rH[i + 1].second + s[i - 1] - '0' + 1)};
    return;
}
pair<unsigned int, unsigned int> getHash(int l, int r)
{
    int len = r - l + 1;
    return {
        (H[r].first - H[l - 1].first * pow1[len]),
        (H[r].second - H[l - 1].second * pow2[len])};
}
pair<unsigned int, unsigned int> getReverseHash(int l, int r)
{
    int len = r - l + 1;
    return {
        (rH[l].first - rH[r + 1].first * pow1[len]),
        (rH[l].second - rH[r + 1].second * pow2[len])};
}
bool palindrome(int l, int r)
{
    return getHash(l, r) == getReverseHash(l, r);
}
void solve()
{
    cin >> s;
    N = s.size() + 5;
    pre();
    calc();
    vector<long long> dp(s.size() + 5, 0);
    dp[1] = 1;
    for (int i = 2; i <= s.size(); i++)
        if (palindrome(1, i))
            dp[i] = 1 + dp[i / 2];
    long long ans = 0;
    for (int i = 1; i <= s.size(); i++)
        ans += dp[i];
    cout << ans;
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}